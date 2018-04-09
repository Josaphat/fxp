cmake_minimum_required(VERSION 3.1.3)

project(fixedpoint C)



add_library(fixedpoint fixedpoint.c)
add_library(fixedpoint::fixedpoint ALIAS fixedpoint)

enable_testing()
add_executable(tests tests.c)
target_link_libraries(tests PUBLIC fixedpoint::fixedpoint)
add_test(all_tests tests)
