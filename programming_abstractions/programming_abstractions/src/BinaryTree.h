#pragma once
#include <iostream>
#include <vector>

struct TreeNode
{
	int data;
	TreeNode* left;
	TreeNode* right;

	TreeNode(int data, TreeNode* left, TreeNode* right)
	{
		this->data = data;
		this->left = left;
		this->right = right;
	}

	bool isLeaf() const
	{
		return left == nullptr && right == nullptr;
	}
};

class BinaryTree
{
public:

	//calculate size of BT
	static int size(TreeNode* node)
	{
		if(node == nullptr)
		{
			return 0;
		}
		return 1 + size(node->left) + size(node->right);
	}
	//BFS = level order traversal
	static void printLevelOrder(TreeNode* node)
	{
		//Pretend it is a queue
		std::vector<TreeNode*> q;
		q.emplace_back(node);

		while(!q.empty())
		{
			//remove from queue
			TreeNode* front = q.at(0);
			q.erase(q.begin());

			//Print data
			std::cout << front->data << std::endl;

			//Enqueue children
			if(front->left)
			{
				q.emplace_back(front->left);
			}

			if (front->right)
			{
				q.emplace_back(front->right);
			}
		}
	}
	//DFS traversals
	//Traverse and print data of tree
	static void printPreOrder(TreeNode* node)
	{
		if(node != nullptr)
		{
			std::cout << node->data << std::endl;
			printPreOrder(node->left);
			printPreOrder(node->right);
		}
	}

	static void printInOrder(TreeNode* node)
	{
		if (node != nullptr)
		{
			printInOrder(node->left);
			std::cout << node->data << std::endl;
			printInOrder(node->right);
		}
	}

	static void printPostOrder(TreeNode* node)
	{
		if (node != nullptr)
		{
			printPostOrder(node->left);
			printPostOrder(node->right);
			std::cout << node->data << std::endl;
		}
	}

	//Check if tree contains given val
	static bool contains(TreeNode* node, int val)
	{
		if(node != nullptr)
		{
			if(node->data == val)
			{
				return true;
			}
			if (contains(node->left, val) || contains(node->right,val))
			{
				return true;
			}
		}
		return false;
	}

	//Check if a binary search tree contains given val
	static bool containsBST(TreeNode* node, int val)
	{
		if (node != nullptr)
		{
			if (val == node->data)
			{
				return true;
			} 
			else if(val < node->data)
			{
				return contains(node->left, val);
			}
			else
			{
				return contains(node->right, val); 
			}
		}

		return false;
	}

	static int getMin(TreeNode* node)
	{
		if(node->left == nullptr)
		{
			return node->data;
		}
		return getMin(node->left);
	}

	static int getMax(TreeNode* node)
	{
		if (node->right == nullptr)
		{
			return node->data;
		}
		return getMax(node->right);
	}

	//Add val to BST
	static void addBST(TreeNode*& node, int val)
	{
		if (node != nullptr)
		{
			if (val == node->data)
			{
				//Tree already has the val
				return;
			}
			if (val < node->data)
			{
				addBST(node->left, val);
			}
			else
			{
				addBST(node->right, val);
			}
		}
		else
		{
			node = new TreeNode(val, nullptr, nullptr);
		}
	}

	static void freeTree(TreeNode* node)
	{
		if(node != nullptr)
		{
			freeTree(node->left);
			freeTree(node->right);
			delete node;
		}
	}

	static void remove(TreeNode*& node, int value)
	{
		//Traverse BST to get node u want to remove
		if(value < node->data)
		{
			remove(node->left, value);
		}
		else if (value > node->data)
		{
			remove(node->right, value);
		}
		//Node to remove found
		else
		{
			//Case 1: leaf
			if(node->isLeaf())
			{
				delete node;
				node = nullptr;
			}
			//Case 2: only left subtree
			else if(node->right == nullptr)
			{
				TreeNode* trash = node;
				node = node->left;
				delete trash;
			}
			//Case 3 : only right subtree
			else if(node->left == nullptr)
			{
				TreeNode* trash = node;
				node = node->right;
				delete trash;
			}
			//Case 4: 2 children
			else
			{
				int min = getMin(node->right);
				node->data = min;
				remove(node->right, min);
			}
		}
	}

	static bool compareTree(TreeNode* a, TreeNode* b)
	{
		if ( a == nullptr && b == nullptr)
		{
			return true;
		}
		if(a == nullptr || b == nullptr)
		{
			return false;
		}
		if(a->data != b->data)
		{
			return false;
		}

		return compareTree(a->left, b->left) && compareTree(a->right, b->right);
	}
};  
