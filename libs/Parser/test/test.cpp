#include "Parser.hpp"
#include <gtest/gtest.h>

#define FILE_UNKNOWN_PATH "unknown.txt"
// ... get other file paths by cmake ...


TEST(Parser, file_opening_error) {
    std::string file_name = FILE_UNKNOWN_PATH;
    input::Parser parser;

    EXPECT_ANY_THROW(parser.parse_file(file_name));

}

TEST(Parser, scan_test1) {
    std::string file_name = FILE_TEST1_PATH;
    input::Parser parser;

    std::vector<std::vector<std::string>> check_res = {
        {"2", "0", "command"}, {"5", "288", "kll"}, {"7", "begin"}
    };

    EXPECT_EQ(check_res, parser.parse_file(file_name));
}

TEST(Parser, scan_test2) {
    std::string file_name = FILE_TEST2_PATH;
    input::Parser parser;

    std::vector<std::vector<std::string>> check_res = {
        {"0", "test_double_sep", "", "10", "ok"}, {"10", ";"}, {"12", ";;"},
        {"13", "command", "value"}, {"14", "command", "value"}
    };

    EXPECT_EQ(check_res, parser.parse_file(file_name));
}

TEST(Parser, scan_test3) {
        std::string file_name = FILE_TEST3_PATH;
    input::Parser parser;

    std::vector<std::vector<std::string>> check_res = {};

    EXPECT_EQ(check_res, parser.parse_file(file_name));
}

TEST(Parser, scan_test4) {
        std::string file_name = FILE_TEST4_PATH;
    input::Parser parser;

    std::vector<std::vector<std::string>> check_res = {};

    EXPECT_EQ(check_res, parser.parse_file(file_name));
}
