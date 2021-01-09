#include "stack.h"
#include <cassert>

#if 0
template <typename T>
myStack<T>::myStack(int size) {
	capacity = size;
	stackArr = new int[size];
	assert(stackArr != NULL);
	numElements = 0;
}

template <typename T>
bool myStack<T>::isEmpty() {
	return (numElements == 0);
}

template <typename T>
T myStack<T>::getTop() {
	return (numElements == 0 ? -1 : stackArr[numElements - 1]);
}

template <typename T>
bool myStack<T>::push(T value) {
	if (numElements < capacity) {
		stackArr[numElements] = value;
		numElements++;
		return true;
	}
	else {
		cout << "Stack Full." << endl;
		return false;
	}
}

template <typename T>
T myStack<T>::pop() {
	if (numElements == 0) {
		cout << "Stack Empty" << endl;
		return -1;
	}
	else {
		numElements--;
		return stackArr[numElements];
	}
}

template <typename T>
int myStack<T>::getSize() {
	return numElements;
}

template <typename T>
void myStack<T>::showStack() {
	int i = 0;
	while (i < numElements) {
		cout << '\t' << stackArr[numElements - 1 - i];
		i++;
	}
	cout << '\n';
}


#else


#include "Stack.h"
#include <cassert>

namespace myTest
{
	template <typename T>
	Stack<T>::Stack(int size) : maxCapacity(size), numElements(0)
	{
		stackAddr = new T[size];
		assert(stackAddr != NULL);
	}

	template <typename T>
	int Stack<T>::getSize() const
	{
		return numElements;
	}

	template <typename T>
	bool Stack<T>::isEmpty()
	{
		return numElements == 0;
	}

	template <typename T>
	bool Stack<T>::push(T const& value)
	{
		//check if stack exceeds the max capacity
		if (numElements >= maxCapacity)
		{
			cout << "Stack is Full" << endl;
			return false;
		}
		else
		{
			stackAddr[numElements] = value;
			numElements++;
			return true;
		}
	}

	template <typename T>
	T Stack<T>::top()
	{
		if (numElements == 0)
		{
			cout << "Stack is Empty" << endl;
			throw out_of_range("Stack<>::top(): empty stack");
			//return -1;
		}
		else
		{
			T topEle = stackAddr[numElements];
			//numElements--;
			return topEle;
		}
	}

	template <typename T>
	T Stack<T>::pop()
	{
		if (numElements == 0)
		{
			cout << "Stack is Empty" << endl;
			throw out_of_range("Stack<>::pop(): empty stack");
			//return -1;
		}
		else
		{
			T topEle = stackAddr[numElements];
			numElements--;
			return topEle;
		}
	}

	template <typename T>
	Stack<T>::~Stack()
	{
		cout << "Stack deconstructor called" << endl;
		delete[] stackAddr;
	}
}

#ifdef USE_MAIN
int main()
{
	myTest::Stack<int> st(5);
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);
	st.push(5);
	st.push(6);

	cout << "st.top() = " << st.top() << endl;
	cout << "st.pop() = " << st.pop() << endl;
	cout << "st.top() = " << st.pop() << endl;
	cout << "st.pop() = " << st.pop() << endl;
	cout << "st.pop() = " << st.pop() << endl;
	cout << "st.pop() = " << st.pop() << endl;

	if (st.isEmpty())
		cout << "empty stack" << endl;
	else
		cout << "remaining element: " << st.getSize() << endl;

	return 0;
}
#endif

#endif