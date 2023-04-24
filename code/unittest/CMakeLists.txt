cmake_minimum_required(VERSION 3.10)
project(unittest)

################################
# GTest
################################
# Setup testing
enable_testing()
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIR})

################################
# Unit Tests
################################
# Add test cpp file
add_executable( unittest testlcs.cpp ../src/dplib.cpp)
# Link test executable against gtest & gtest_main
target_link_libraries(unittest gtest gtest_main)
add_test( unittest unittest )