#include <cassert>
#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = nullptr;
}
LinkedList::~LinkedList()
{
}
Node* LinkedList::getHead()
{
	return head;
}
bool LinkedList::isEmpty()
{
	return head == nullptr;
}
void LinkedList::insertNodeBeforeHead(int value)
{
	Node* tmpNode = new Node(value);
	assert(tmpNode != nullptr);
	if (isEmpty())
	{
		head = tmpNode;
		head->nextNode = nullptr;
	}
	else
	{
		Node* curHead = head;
		head = tmpNode;
		head->nextNode = curHead;
	}
}
void LinkedList::insertNodeAfterTail(int value)
{
	Node* tmpNode = new Node(value);
	assert(tmpNode != nullptr);

	if (isEmpty())
	{
		head = tmpNode;
		head->nextNode = nullptr;
		return;
	}

	//find the tail of the list
	Node* tail = head;
	while (tail && tail->nextNode)
		tail = tail->nextNode;

	tail->nextNode = tmpNode;
	tmpNode->nextNode = nullptr;
}
bool LinkedList::search(int value)
{
	if (isEmpty())
		return nullptr;

	Node* cur = head;
	while (cur)
	{
		if (cur->data == value)
			return true;

		cur = cur->nextNode;
	}

	return false;
}
bool LinkedList::deleteAtHead(int value)
{
	if (isEmpty() || !head->nextNode || head->nextNode->data != value)
		return false;

	Node* nxt_nxt = head->nextNode->nextNode;
	head->nextNode = nxt_nxt;

	return true;
}
bool LinkedList::deleteNode(int value)
{
	Node* cur = head;
	while (cur)
	{
		if (cur->nextNode == nullptr)
		{
			if (cur->data == value)
			{
				head = nullptr;
				return true;
			}
			else
			{
				return false;
			}
		}

		else if (cur->nextNode->data == value)
		{
			cur->nextNode = cur->nextNode->nextNode;
			return  true;
		}
		else
			cur = cur->nextNode;
		
	}

	return false;
}