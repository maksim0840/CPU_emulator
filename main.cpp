#include <iostream>
#include "libs/Stack/src/Stack.cpp"
#include "libs/Stack/include/Stack.hpp"


int main() {

	storage::Stack<int> stack1({10, 12, 48});
	std::cout << stack1.top() << ' ';
	stack1.pop();
	std::cout << stack1.top() << ' ';
	stack1.pop();
	std::cout << stack1.top() << ' ';
	stack1.pop();
	std::cout << stack1.top() << ' ';

}
