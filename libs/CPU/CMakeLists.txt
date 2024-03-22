
add_library(CPU
	src/CPU.cpp
	include/CPU.hpp)

add_executable(test_CPU test/test.cpp)
add_test(CPU test_CPU)

set(test_files ${CMAKE_CURRENT_SOURCE_DIR}/test/test_files)
target_compile_definitions(test_CPU PRIVATE "FILE_PUSH_PATH=\"${test_files}/push.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_POP_PATH=\"${test_files}/pop.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_REGISTERS_PATH=\"${test_files}/registers.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_ADD_PATH=\"${test_files}/add.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_SUB_PATH=\"${test_files}/sub.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_MUL_PATH=\"${test_files}/mul.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_DIV_PATH=\"${test_files}/div.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JMP_PATH=\"${test_files}/jmp.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JEQ_PATH=\"${test_files}/jeq.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JNE_PATH=\"${test_files}/jne.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JA_PATH=\"${test_files}/ja.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JAE_PATH=\"${test_files}/jae.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JB_PATH=\"${test_files}/jb.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_JBE_PATH=\"${test_files}/jbe.txt\"")
target_compile_definitions(test_CPU PRIVATE "FILE_CALL_PATH=\"${test_files}/call.txt\"")

gtest_discover_tests(test_CPU)