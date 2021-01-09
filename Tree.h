#ifndef TREE_HPP
#define TREE_HPP

class TreeNode
{
public:
	TreeNode* leftChild;
	TreeNode* rightChild;
	int value;
	TreeNode();
	TreeNode(int val);
};

class BinarySearchTree
{
public:
	BinarySearchTree();
	BinarySearchTree(int rootValue);
	TreeNode* getRoot();
	TreeNode* insert(TreeNode* currentNode, int val);
	void insertBST(int val);
	bool Delete(TreeNode* currentNode, int value);
	bool deleteBST(int value);
	TreeNode* findLeastNode(TreeNode* currentNode);
	void inOrderPrint(TreeNode * currentNode);
private:
	TreeNode* root;
};

#endif
