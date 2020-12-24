cmake_minimum_required(VERSION 3.1.3)

project(fixedpoint C CXX)

if (MSVC)
  add_compile_options(/W3)
else()
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

add_library(fixedpoint fixedpoint.c)
add_library(fixedpoint::fixedpoint ALIAS fixedpoint)

enable_testing()
add_executable(tests tests.c)
target_link_libraries(tests PUBLIC fixedpoint::fixedpoint)
add_test(c_tests tests)

add_executable(fxp_tests fxp_tests.cpp)
target_link_libraries(tests PUBLIC fixedpoint::fixedpoint)
add_test(fxp_tests fxp_tests)
