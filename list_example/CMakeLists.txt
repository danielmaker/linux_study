cmake_minimum_required(VERSION 2.8)

set(CMAKE_BUILD_TYPE Debug)

message( CMAKE_SYSTEM_NAME=${CMAKE_SYSTEM_NAME} )
message( CMAKE_BUILD_TYPE=${CMAKE_BUILD_TYPE} )
message( CMAKE_C_COMPILER=${CMAKE_C_COMPILER} )

#############################

# program 1: list_example
add_executable( list_example list_example.c)

# program 2: hashtable_example
add_executable( hashtable_example hashtable_example.c)

