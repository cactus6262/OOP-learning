#include "queue.h"
#include <cassert>

myQueue::myQueue(int capacity) : maxCapacity(capacity), front(0), back(0), numElement(0)
{
	qAddr = new int[capacity];
	assert(qAddr != NULL);
}

bool myQueue::enqueue(int const& elem)
{
	//check if queue is full
	if (numElement >= maxCapacity)
	{
		cout << "queue is Full" << endl;
		return false;
	}
	else
	{
		qAddr[back] = elem;
		back++;
		numElement++;
		if (back >= maxCapacity)
			back = 0;
	}
}

int myQueue::dequeue()
{
	//check if queue is empty
	if (numElement == 0)
	{
		cout << "queue is empty" << endl;
		return -1;
	}
	else
	{
		//get the front element
		int topElem = qAddr[front];
		front++;
		numElement--;
		if (front >= maxCapacity)
			front = 0;

		return topElem;
	}
}

int myQueue::getFront()
{
	//check if queue is empty
	if (numElement == 0)
	{
		cout << "queue is empty" << endl;
		return -1;
	}
	else
	{
		//get the front element
		int topElem = qAddr[front];
		//front++;
		//numElement--;
		//if (front > maxCapacity)
			//front = 0;

		return topElem;
	}
}

int myQueue::getSize()
{
	return numElement;
}

bool myQueue::isEmpty()
{
	return numElement == 0;
}