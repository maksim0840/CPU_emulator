#include "../../Starter/src/Starter.cpp"
#include <gtest/gtest.h>


TEST(Cpu, push) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_PUSH_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {15};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, pop) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_POP_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {10};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, registers) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_REGISTERS_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {15, 10};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, add) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_ADD_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {25};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, sub) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_SUB_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {5};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, mul) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_MUL_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {150};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, div) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_DIV_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {10};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, jmp) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JMP_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {10};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, jeq) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JEQ_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {7};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, jne) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JNE_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {7};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, ja) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JA_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {7};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, jae) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JAE_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {7};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, jb) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JB_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {7};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, jbe) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_JBE_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {7};

	EXPECT_EQ(result, starter.get_result());

};

TEST(Cpu, call) {
    run::Starter<int> starter;

    int argc = 2;
    char* argv[] = {"", FILE_CALL_PATH};
	starter.execute(argc, argv);

	std::vector<int> result = {15};

	EXPECT_EQ(result, starter.get_result());

};