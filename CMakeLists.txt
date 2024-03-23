cmake_minimum_required(VERSION 3.22.1)
project(MYVECTOR)

# Include Google Test
add_subdirectory(googletest)

# Add include directories for Google Test
include_directories(googletest/include)

# Add your test executable
add_executable(myVectorTest MyVector_impl.h MyVectorTest.cpp)

# Link against Google Test
target_link_libraries(myVectorTest PRIVATE gtest gtest_main)
