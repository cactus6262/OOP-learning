#ifndef STACK_HPP
#define STACK_HPP

#if 0
#include <iostream>

using namespace std;

template <typename T>
class myStack {
private:
	T * stackArr;
	int capacity;
	int numElements;
public:
	myStack(int size);
	bool isEmpty();
	T getTop();
	bool push(T const& value);
	T pop();
	int getSize();
	void showStack();
};
#else

#include <iostream>
using namespace std;

namespace myTest
{
	//using T = int;
	template <typename T>
	class Stack
	{
	public:
		Stack(int size);
		~Stack();
		Stack(Stack& other) = default;
		Stack& operator=(Stack& other) = default;

		int getSize() const;
		bool isEmpty();

		bool push(T const& value);
		T top();
		T pop();

	private:
		int maxCapacity;
		int numElements;
		T* stackAddr;
	};
}
#endif

#endif
