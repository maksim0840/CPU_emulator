
add_library(Parser
	src/Parser.cpp
	include/Parser.hpp)

add_executable(test_Parser test/test.cpp)
add_test(Parser test_Parser)

set(test_files ${CMAKE_CURRENT_SOURCE_DIR}/test/test_files)
target_compile_definitions(test_Parser PRIVATE "FILE_TEST1_PATH=\"${test_files}/test1.txt\"")
target_compile_definitions(test_Parser PRIVATE "FILE_TEST2_PATH=\"${test_files}/test2.txt\"")
target_compile_definitions(test_Parser PRIVATE "FILE_TEST3_PATH=\"${test_files}/test3.txt\"")
target_compile_definitions(test_Parser PRIVATE "FILE_TEST4_PATH=\"${test_files}/test4.txt\"")

gtest_discover_tests(test_Parser)
