
#include "Tree.h"
#include <iostream>
using namespace std;

TreeNode::TreeNode() : leftChild(nullptr), rightChild(nullptr), value(0)
{
}
TreeNode::TreeNode(int val) : leftChild(nullptr), rightChild(nullptr)
{
	value = val;
}

BinarySearchTree::BinarySearchTree()
{
	root = nullptr;
}
BinarySearchTree::BinarySearchTree(int rootValue)
{
	root = new TreeNode(rootValue);
}

TreeNode* BinarySearchTree::getRoot()
{
	return root;
}

bool BinarySearchTree::Delete(TreeNode * currentNode, int value) {

	if (root == NULL) {
		return false;
	}
	TreeNode * parent = currentNode; //To Store parent of currentNode
	while (currentNode != NULL && (currentNode->value != value)) {
		parent = currentNode;
		if (currentNode->value > value)
			currentNode = currentNode->leftChild;
		else
			currentNode = currentNode->rightChild;

	}

	if (currentNode == NULL) {
		return false;
	}
	else if (currentNode->leftChild == NULL && currentNode->rightChild == NULL) {
		//1. Node is Leaf Node
		//if that leaf node is the root (a tree with just root)
		if (root->value == currentNode->value) {
			delete root;
			root = NULL;
			return true;
		}
		else if (currentNode->value < parent->value) {
			delete parent->leftChild;
			parent->leftChild = NULL;
			return true;
		}
		else {
			delete parent->rightChild;
			parent->rightChild = NULL;
			return true;
		}
	}
	else if (currentNode->rightChild == NULL) {

		if (root->value == currentNode->value) {
			delete root;
			root = currentNode->leftChild;
			return true;
		}
		else if (currentNode->value < parent->value) {

			delete parent->leftChild;
			parent->leftChild = currentNode->leftChild;
			return true;
		}
		else {
			delete parent->rightChild;
			parent->rightChild = currentNode->leftChild;
			return true;
		}

	}
	else if (currentNode->leftChild == NULL) {

		if (root->value == currentNode->value) {
			delete root;
			root = currentNode->rightChild;
			return true;
		}
		else if (currentNode->value < parent->value) {
			delete parent->leftChild;
			parent->leftChild = currentNode->rightChild;
			return true;
		}
		else {
			delete parent->rightChild;
			parent->rightChild = currentNode->rightChild;
			return true;
		}

	}
	else {
		//Find Least Value Node in right-subtree of current Node
		TreeNode * leastNode = findLeastNode(currentNode->rightChild);
		//Set CurrentNode's Data to the least value in its right-subtree
		int tmp = leastNode->value;
		Delete(root, tmp);
		currentNode->value = tmp;
		//Delete the leafNode which had the least value
		return true;
	}

}

TreeNode* BinarySearchTree::insert(TreeNode* currentNode, int val)
{
	if (currentNode == nullptr)
		return new TreeNode(val);

	int curVal = currentNode->value;
	if (curVal > val)
		currentNode->rightChild = insert(currentNode->rightChild, val);
	else
		currentNode->leftChild = insert(currentNode->leftChild, val);

	return currentNode;
}
void BinarySearchTree::insertBST(int val)
{
	if (getRoot() == nullptr)
	{
		root = new TreeNode(val);
		return;
	}

	insert(getRoot(), val);
}
//Helper function to find least value node in right-subtree of currentNode
TreeNode * BinarySearchTree::findLeastNode(TreeNode * currentNode) {

	TreeNode * temp = currentNode;
	while (temp->leftChild != nullptr) {
		temp = temp->leftChild;
	}

	return temp;
}

bool BinarySearchTree::deleteBST(int value) {
	return Delete(root, value);
}

void BinarySearchTree::inOrderPrint(TreeNode * currentNode) {
	if (currentNode != NULL) {
		inOrderPrint(currentNode->leftChild);
		cout << currentNode->value << endl;
		inOrderPrint(currentNode->rightChild);
	}
}