#include "SetBST.h"

SetBST::SetBST()
	:root(nullptr), size(0)
{
}

SetBST::~SetBST()
{
	postOrderClear(root);
	root = nullptr;
}

void SetBST::add(int n)
{
	addHelper(n, root);
}

int SetBST::findMin() const
{
	return findMinHelper(root);
}

int SetBST::findMax() const
{
	return findMaxHelper(root);
}

bool SetBST::contains(int n) const
{
	return containsHelper(n, root);
}

void SetBST::remove(int n)
{
	removeHelper(n, root);
}

int SetBST::getSize() const
{
	return size;
}

bool SetBST::isEmpty() const
{
	return root == nullptr;
}

void SetBST::postOrderClear(SetNode* node)
{
	if(node != nullptr)
	{
		postOrderClear(node->left);
		postOrderClear(node->right);
		delete node;
	}
}

int SetBST::findMinHelper(SetNode* node) const
{
	//TODO check for empty list?
	if(node->left == nullptr)
	{
		return node->data;
	}
	return findMinHelper(node->left);
}

int SetBST::findMaxHelper(SetNode* node) const
{
	//TODO check for empty list?
	if (node->right == nullptr)
	{
		return node->data;
	}
	return findMaxHelper(node->right);
}

bool SetBST::containsHelper(int value, SetNode* node) const
{
	if(node == nullptr)
	{
		return false;
	}
	if(node->data == value)
	{
		return true;
	}
	if(value < node->data)
	{
		return containsHelper(value, node->left);
	}

	return containsHelper(value, node->right);
}

void SetBST::addHelper(int value, SetNode*& node)
{

	if (node != nullptr)
	{
		if (value == node->data)
		{
			return;
		}

		if (value < node->data) 
		{
			addHelper(value, node->left);
		}
		else
		{
			addHelper(value, node->right);
		}
	}
	else //Node found
	{
		node = new SetNode(value);
		size++;
	}
}

void SetBST::removeHelper(int value, SetNode*& node)
{
	//Node not in set
	if (node == nullptr)
	{
		return;
	}
	//Traverse tree to find node
	if(value < node->data)
	{
		removeHelper(value, node->left);
	}
	else if (value > node->data)
	{
		removeHelper(value, node->right);
	}
	//Node found
	else
	{
		//Case 1: Leaf
		if(node->isLeaf())
		{
			delete node;
			node = nullptr;
			size--;
		}
		//Case 2: only left subtree
		else if(node->right == nullptr)
		{
			SetNode* trash = node;
			node = node->left;
			delete trash;
			size--;
		}
		//Case 3: only right subtree
		else if (node->left == nullptr)
		{
			SetNode* trash = node;
			node = node->right;
			delete trash;
			size--;
		}
		//Case 4: 2 children
		else
		{
			//Find min or max from right or left
			int min = findMinHelper(node->right);
			node->data = min;
			//Min node will be one of above cases <= 1 child
			removeHelper(min, node->right);
		}
	}
}

std::ostream& operator<<(std::ostream& out, SetBST& set)
{
	int max = set.findMax();
	out << "[";
	set.inOrderTraversal(out, set.root, max);
	out << "]";
	return out;
}

void SetBST::inOrderTraversal(std::ostream& out, SetNode* node, int max) {
	if (node == nullptr) {
		return;
	}
	inOrderTraversal(out, node->left, max);
	out << node->data;
	if (node->data != max) {
		out << ", ";
	}
	inOrderTraversal(out, node->right, max);
}
