cmake_minimum_required(VERSION 3.1)

project(slt_str_manip)

enable_testing()

include_directories(
  ./tests
  ./include
)

SET(STR_MANIP_TESTS
  test_split
)

FOREACH(TEST ${STR_MANIP_TESTS})
  add_executable(${TEST} tests/${TEST}.cpp)
  target_compile_options(${TEST} PRIVATE
                       "$<$<C_COMPILER_ID:Clang>:--std=c++17>"
                       "$<$<C_COMPILER_ID:GNU>:--std=c++17>"
                       "$<$<C_COMPILER_ID:MSVC>:/std:c++17>")

  add_test(${TEST} ${TEST})
ENDFOREACH(TEST)

