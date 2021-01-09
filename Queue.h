#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iostream>

using namespace std;

class myQueue
{
public:
	myQueue(int capacity);
	bool enqueue(int const& elem);
	int dequeue();
	int getFront();
	int getSize();
	bool isEmpty();
private:
	int *qAddr;
	int maxCapacity;
	int front;
	int back;
	int numElement;
};

#endif
