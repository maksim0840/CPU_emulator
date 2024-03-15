#include "../include/Stack.hpp"

namespace storage {

	/* Public methods */


	template <typename T>
	void Stack<T>::push(const T& val) {
		stack_cell* cell = new stack_cell{.back_ptr = end, .value = val};

		end = cell;
		if (begin != nullptr) {
			begin = cell;
		}
	}

	template <typename T>
	void Stack<T>::push(T&& val) {
		stack_cell* cell = new stack_cell{.back_ptr = end, .value = val};

		end = cell;
		if (begin != nullptr) {
			begin = cell;
		}
	}

	template <typename T>
	void Stack<T>::pop() {
		if (end == nullptr) {
			throw no_more_elements();
		}

		stack_cell* buff = end->back_ptr;
		delete[] end;
		end = buff;

		if (end == nullptr) {
			begin = nullptr;
		}
	}

	template <typename T>
	T& Stack<T>::top() {
		if (end != nullptr) {
			return end->value;
		}
		throw no_more_elements();
	}

	template <typename T>
	const T& Stack<T>::top() const {
		if (end != nullptr) {
			return end->value;
		}
		throw no_more_elements();
	}

	template <typename T>
	std::vector<T> Stack<T>::to_vector() const{ // for ctest
		std::vector<T> vec;
		for (stack_cell* element = end; element != nullptr; element = element->back_ptr) {
			vec.push_back(element->value);
		}
		std::reverse(vec.begin(), vec.end());
		return vec;
	}

	/* Constructors */


	// Default constructor
	template <typename T>
	Stack<T>::Stack() = default;

	// Init_list constructor - {1, 2, 3}
	template <typename T>
	Stack<T>::Stack(const std::initializer_list<T>& init_list) {
		for (const T& elem : init_list) {
			push(elem);
		}
	}

	// Destructor
	template <typename T>
	Stack<T>::~Stack() {
		pass_by_recursion(end, Action::DELETE); // delete values
	}

	// Copy constructor
	template <typename T>
	Stack<T>::Stack(const Stack& stack) {
		pass_by_recursion(stack.end, Action::COPY); // copy values
	}

	// Move constructor
	template <typename T>
	Stack<T>::Stack(Stack&& stack) {
		move_cells(*this, stack);
	}


	/* Operators */


	// Copy assignment to Stack operator
	template <typename T>
	Stack<T>& Stack<T>::operator=(const Stack& stack) {
		if (this == &stack) { // the "same objects" situation
			return *this;
		}
		Stack<T> new_stack(stack); // copy constructor
		move_cells(*this, new_stack);
		return *this;
	}

	// Copy assignment to init_list operator - {1, 2, 3}
	template <typename T>
	Stack<T>& Stack<T>::operator=(const std::initializer_list<T>& init_list) {
		Stack<T> new_stack(init_list); // copy constructor
		move_cells(*this, new_stack);
		return *this;
	}

	// Move assignment to init_list operator - {1, 2, 3}
	template <typename T>
	Stack<T>& Stack<T>::operator=(std::initializer_list<T>&& init_list) {
		Stack<T> new_stack = std::move(init_list); // move
		move_cells(*this, new_stack);
		return *this;
	}

	// Move assignment to Stack operator
	template <typename T>
	Stack<T>& Stack<T>::operator=(Stack&& stack) {
		if (this == &stack) { // the "same objects" situation
			return *this;
		}
		Stack<T> new_stack = std::move(stack); // move
		move_cells(*this, new_stack);
		return *this;
	}
	
	
	/* Private methods */


	template <typename T>
	void Stack<T>::pass_by_recursion(const stack_cell* element, const Action act) {
		if (element == nullptr) {
			return;
		}
		pass_by_recursion(element->back_ptr, act);

		if (act == Action::COPY) {
			push(element->value);
		}
		else if (act == Action::DELETE) {
			delete[] element;
		}
	}

	// Fill "stack_to" by "stack_from's" elements
	template <typename T>
	void Stack<T>::move_cells(Stack& stack_to, Stack& stack_from) { 
		stack_to.end = stack_from.end;
		stack_to.begin = stack_from.begin;
		// Set nullptrs to avoid "cells" deletion by distructor in "stack_from"
		stack_from.end = nullptr;
		stack_from.begin = nullptr;
	}

}

