## 2021 modifications

### Can be cross-compiled for ARM.

Create `.build_arm` subfolder and inside execute:

```
$> cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-arm.cmake ..
```

You can also specify build type and extra compiler flags as below:

```
$> cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-O0 -ggdb" -DCMAKE_TOOLCHAIN_FILE=../toolchain-arm.cmake  ..
```

Then run `make`. Built example programs can then be executed with `qemu`:

```
$> qemu-arm -L /usr/arm-linux-gnueabihf/ example1
```


### Can be cross-compiled for PowerPC.

Create `.build_ppc` subfolder and inside execute:

```
$> cmake -DCMAKE_TOOLCHAIN_FILE=../toolchain-ppc.cmake ..
```

You can also specify build type and extra compiler flags as below:

```
$> cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_CXX_FLAGS="-O0 -ggdb" -DCMAKE_TOOLCHAIN_FILE=../toolchain-ppc.cmake  ..
```

Then run `make`. Built example programs can then be executed with `qemu`:

```
$> qemu-ppc -L /usr/powerpc-linux-gnu/ ./example1
```

### Examples' status

* `example1` - runs correctly on X86_64, ARM, and PowerPC.
* `example2` - runs correctly on X86_64, ARM, and PowerPC.
* `example3` - runs correctly on X86_64 and PowerPC. On ARM it also passes, but `time` is not an IRELATIVE symbol in ARM's libc.
* `example5` - runs correctly on X86_64, ARM, and PowerPC.
* `example6` - runs correctly on X86_64, ARM, and PowerPC.
* `example7` - runs correctly on X86_64, ARM, and PowerPC.
* `example9` - runs correctly on X86_64, ARM, and PowerPC.

---

ELFspy is a library for linux for writing tests using [fakes and spies](http://xunitpatterns.com/Test%20Double.html) in C++. For very large call graphs, the testing of the higher nodes can be difficult due to the sum of dependencies of lower nodes e.g. databases, network connections etc. Adding fakes and spies to the callees of a function allows it to be tested in isolation without the inherited dependencies.

ELFspy works by allowing code to externally modify an existing implementation/library of a program. This is achieved by changing function addresses in the global offset tables of the running program, so that these are redirected to a different function created by ELFspy. This allows new functions to be interjected between the caller and the callee to spy on the arguments and return value. In addition the original function can be replaced with a simulation (fake) of the original. The code under test needs no changes and is unaware of the additional calls that are being made in between a caller and a callee.

Call graph before change

![](https://github.com/mollismerx/elfspy/blob/master/images/spy%20before.png)

External code:
```C++
auto add_spy = SPY(&add);
```
Call graph after change(the code does not change, but the runtime execution does)

![](https://github.com/mollismerx/elfspy/blob/master/images/spy%20after.png)

This technique relies on code being compiled as [position independent code](https://en.wikipedia.org/wiki/Position-independent_code) and uses the Executable and Linking Format([ELF](https://refspecs.linuxfoundation.org/elf/elf.pdf)) information found in the executable and its shared libraries to find the global offset table entries and modify them.

To see how ELFspy can be used start by reading this [example](https://github.com/mollismerx/elfspy/wiki/Example-01:-Spying-on-code)
