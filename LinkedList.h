#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include "Node.h"
class LinkedList
{
public:
	LinkedList();
	~LinkedList();
	Node* getHead();
	bool isEmpty();
	void insertNodeBeforeHead(int value);
	void insertNodeAfterTail(int value);
	bool search(int value);
	bool deleteAtHead(int value);
	bool deleteNode(int value);
private:
	Node* head;
};

#endif
