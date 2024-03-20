
add_library(CPU
	src/CPU.cpp
	include/CPU.hpp)

add_executable(test_CPU test/test.cpp)
add_test(CPU test_CPU)

gtest_discover_tests(test_CPU)