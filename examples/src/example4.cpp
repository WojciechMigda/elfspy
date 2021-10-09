#include "elfspy/SPY.h"
#include "elfspy/Fake.h"

#include <iostream>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <stddef.h>
#include <assert.h>

char as[] = "ABCDEFGHIJ";
char * s = as;

int main(int argc, char** argv)
{
  spy::initialise(argc, argv);

  auto memchr_spy = SPY((const void *(*)(const void *, int, size_t))&memchr);

  // Not really a useful example of a fake memchr,
  // but on platforms where memchr is an indirect symbol (X64 and ARM)
  // faking it works. Hence, this example fills a gap on ARM, on which
  // time being used in example3 is not an indirect symbol.
  auto memchr_replacement = [&memchr_spy](const void *s, int c, size_t n) -> const void *
  {
    std::cout << "Fake memchr called\n";
    const void * rv = memchr_spy.invoke_real(s, c, n);

    if (rv != NULL)
    {
      return rv;
    }

    rv = memchr_spy.invoke_real(s, c ^ 0xFF, n);

    return rv;
  };

  auto memchr_fake = spy::fake(memchr_spy, memchr_replacement);

  void * rv = memchr(s, 'E' ^ 0xFF, strlen(s) + 1);

  assert(rv == (s + 4));

  rv = memchr(s, 'D', strlen(s) + 1);

  assert(rv == (s + 3));

  return 0;
}
