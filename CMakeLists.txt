cmake_minimum_required( VERSION 3.5 )

project( ElfSpyProject VERSION 0.0.1 LANGUAGES CXX )

set( CMAKE_POSITION_INDEPENDENT_CODE ON )

add_subdirectory( lib )

add_subdirectory( examples )
