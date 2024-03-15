#pragma once
#include <initializer_list>
#include <utility> // std::move()
#include <vector>
#include <algorithm> // vec.reverse()

namespace storage {
	template <typename T>
	class Stack {
		public:
			// 	Methods
			void push(const T&);
			void pop();
			T& top() const;
			std::vector<T> to_vector() const;

			// Constructors
			Stack();
			Stack(const std::initializer_list<T>&);
			~Stack();
			Stack(const Stack&);
			Stack(Stack&& stack);

			// Operators
			Stack& operator=(const Stack&);
			Stack& operator=(const std::initializer_list<T>&);
			Stack& operator=(Stack&&);
			Stack& operator=(std::initializer_list<T>&&);

		private:
			struct stack_cell {
				stack_cell* back_ptr;
				T value;
			};
			stack_cell* begin = nullptr; // stack first element ptr
			stack_cell* end = nullptr; // stack last element ptr

			enum class Action {
				COPY,
				DELETE			
			};
			void pass_by_recursion(const stack_cell*, const Action);

			void move_cells(Stack&, Stack&);
	};

	struct no_more_elements{}; // IN PROGRESS

}