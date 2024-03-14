#include "../libs/Stack/include/Stack.hpp"
#include "../libs/Stack/src/Stack.cpp"
#include <gtest/gtest.h>


TEST(Constructors, constructor) {

    storage::Stack<int> stack1({10, 12});
    storage::Stack<int> stack2(stack1);
    storage::Stack<char> stack3({'a', 'b', '\0', '_'});
    storage::Stack<char> stack4(stack3);
    storage::Stack<double> stack5({10.954, 0.001, -890.1});
    storage::Stack<double> stack6(stack5);

    std::vector<int> check_res1 = {10, 12};
    std::vector<int> check_res2 = {10, 12};
    std::vector<char> check_res3 = {'a', 'b', '\0', '_'};
    std::vector<char> check_res4 = {'a', 'b', '\0', '_'};
    std::vector<double> check_res5 = {10.954, 0.001, -890.1};
    std::vector<double> check_res6 = {10.954, 0.001, -890.1};

    EXPECT_EQ(stack1.to_vector(), check_res1);
    EXPECT_EQ(stack2.to_vector(), check_res2);
    EXPECT_EQ(stack3.to_vector(), check_res3);
    EXPECT_EQ(stack4.to_vector(), check_res4);
    EXPECT_EQ(stack5.to_vector(), check_res5);
    EXPECT_EQ(stack6.to_vector(), check_res6);
}


TEST(Assignment_operators, Assignment_operator) {
    
    storage::Stack<int> stack1;
    storage::Stack<int> stack2;
    storage::Stack<char> stack3;
    storage::Stack<char> stack4;
    storage::Stack<double> stack5;
    storage::Stack<double> stack6;

    stack1 = {0, 0, 9};
    stack2 = stack1;
    stack2 = stack2;
    stack3 = {};
    stack4 = stack3;
    stack5 = {-1};
    stack6 = stack5;


    std::vector<int> check_res1 = {0, 0, 9};
    std::vector<int> check_res2 = {0, 0, 9};
    std::vector<char> check_res3 = {};
    std::vector<char> check_res4 = {};
    std::vector<double> check_res5 = {-1};
    std::vector<double> check_res6 = {-1};

    EXPECT_EQ(stack1.to_vector(), check_res1);
    EXPECT_EQ(stack2.to_vector(), check_res2);
    EXPECT_EQ(stack3.to_vector(), check_res3);
    EXPECT_EQ(stack4.to_vector(), check_res4);
    EXPECT_EQ(stack5.to_vector(), check_res5);
    EXPECT_EQ(stack6.to_vector(), check_res6);
}


TEST(Methods, push) {
    storage::Stack<int> stack1({10, 12});
    storage::Stack<char> stack2({'a', 'b', '\0', '_'});
    storage::Stack<double> stack3({10.954, 0.001, -890.1});

    stack1.push(-5);
    stack2.push('c');
    stack2.push('0');
    stack3.push(10.0);
    stack3.push(-10.0);
    stack3.push(190.001);

    std::vector<int> check_res1 = {10, 12, -5};
    std::vector<char> check_res2 = {'a', 'b', '\0', '_', 'c', '0'};
    std::vector<double> check_res3 = {10.954, 0.001, -890.1, 10.0, -10.0, 190.001};
    EXPECT_EQ(stack1.to_vector(), check_res1);
    EXPECT_EQ(stack2.to_vector(), check_res2);
    EXPECT_EQ(stack3.to_vector(), check_res3);
}


TEST(Methods, pop) {
    storage::Stack<int> stack1({});
    storage::Stack<char> stack2({'a', 'b', '\0'});
    storage::Stack<double> stack3({10.954, 0.001, -890.1});

    stack2.pop();
    stack2.pop();
    stack3.pop();
    stack3.pop();
    stack3.pop();

    std::vector<char> check_res2 = {'a'};
    std::vector<double> check_res3 = {};

    EXPECT_ANY_THROW(stack1.pop());
    EXPECT_EQ(stack2.to_vector(), check_res2);
    EXPECT_EQ(stack3.to_vector(), check_res3);
}

TEST(Methods, top) {
    storage::Stack<int> stack1({});
    storage::Stack<char> stack2({'a', 'b', '\0'});
    storage::Stack<double> stack3({10.954, 0.001, -890.1});

    EXPECT_ANY_THROW(stack1.top());
    EXPECT_EQ(stack2.top(), '\0');
    EXPECT_EQ(stack3.top(), -890.1);
}
