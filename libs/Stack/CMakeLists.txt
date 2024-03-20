
add_library(Stack
	src/Stack.cpp
	include/Stack.hpp)

add_executable(test_Stack test/test.cpp)
add_test(Stack test_Stack)

gtest_discover_tests(test_Stack)