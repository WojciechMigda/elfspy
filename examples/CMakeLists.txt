cmake_minimum_required( VERSION 3.5 )

project( ElfSpyExamples
         VERSION 0.0.1
         DESCRIPTION "Example apps for ElfSpy." )

add_library( demo SHARED "src/dummy.cpp" )
target_sources( demo
    PRIVATE   "src/demo.cpp"
)

add_executable( example1 "src/dummy.cpp" )
target_sources( example1 PRIVATE "src/example1.cpp" )
target_link_libraries( example1
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example1 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example1 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)

add_executable( example2 "src/dummy.cpp" )
target_sources( example2 PRIVATE "src/example2.cpp" )
target_link_libraries( example2
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example2 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example2 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)

add_executable( example3 "src/dummy.cpp" )
target_sources( example3 PRIVATE "src/example3.cpp" )
target_link_libraries( example3
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example3 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example3 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)

add_executable( example5 "src/dummy.cpp" )
target_sources( example5 PRIVATE "src/example5.cpp" )
target_link_libraries( example5
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example5 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example5 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)

add_executable( example6 "src/dummy.cpp" )
target_sources( example6 PRIVATE "src/example6.cpp" )
target_link_libraries( example6
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example6 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example6 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)

add_executable( example7 "src/dummy.cpp" )
target_sources( example7 PRIVATE "src/example7.cpp" )
target_link_libraries( example7
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example7 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example7 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)

add_executable( example9 "src/dummy.cpp" )
target_sources( example9 PRIVATE "src/example9.cpp" )
target_link_libraries( example9
    PRIVATE elfspy::elfspy demo )
target_compile_definitions( example9 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_COMPILE_DEFINITIONS>"
)
target_include_directories( example9 PRIVATE
    "$<TARGET_PROPERTY:elfspy,INTERFACE_INCLUDE_DIRECTORIES>"
)
