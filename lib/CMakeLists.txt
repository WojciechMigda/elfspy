cmake_minimum_required( VERSION 3.5 )

project( ElfSpy
         VERSION 0.0.1
         DESCRIPTION "ElfSpy library." )

# An OBJECT-library, used to only compile common sources once
# which are used in both math-libraries.
add_library( elfspy_ObjLib OBJECT "src/dummy.cpp" )
target_sources( elfspy_ObjLib
    PRIVATE   "src/Call.cpp"
              "src/ELFInfo.cpp"
              "src/Error.cpp"
              "src/Fail.cpp"
              "src/GOTEntry.cpp"
              "src/MFile.cpp"
              "src/Report.cpp"
              "src/SectionHeader.cpp"
              "src/SPY.cpp"
)

# Required include search-paths
target_include_directories( elfspy_ObjLib
    PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include" )

# A shared library for basic-math functionality.
add_library( elfspy SHARED "src/dummy.cpp" )
target_sources( elfspy
    PRIVATE $<TARGET_OBJECTS:elfspy_ObjLib> )
# Inherit the usage-requirements from direct dependency 'elfspy_ObjLib'
# (and its indirect dependency).
target_include_directories( elfspy
    PUBLIC
        $<TARGET_PROPERTY:elfspy_ObjLib,INTERFACE_INCLUDE_DIRECTORIES> )
target_compile_features( elfspy
    PUBLIC $<TARGET_PROPERTY:elfspy_ObjLib,INTERFACE_COMPILE_FEATURES> )

# Create ALIAS targets.
add_library( elfspy::elfspy ALIAS elfspy )
