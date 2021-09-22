cmake_minimum_required(VERSION 3.5)
project(LinkedList CXX)

# require a C++11 compiler for all targets
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

set(NODE_SOURCE
  Node.hpp)

set(LIST_SOURCE
  LinkedList.hpp)
 
set(TEST_SOURCE
 student_tests.cpp)

# create unittests
set(SOURCE ${LIST_SOURCE} ${NODE_SOURCE})

# create unittests
add_executable(student-tests catch.hpp student_catch.cpp ${SOURCE} ${TEST_SOURCE})

## REMOVE ALL BELOW FOR GRADER
# some simple tests
enable_testing()
add_test(student-tests student-tests)

add_custom_target(submission COMMAND
  ${CMAKE_COMMAND} -E tar "cfv" "${CMAKE_CURRENT_BINARY_DIR}/submission.zip" --format=zip
  LinkedList.txx student_tests.cpp
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
