#pragma once
#include <ostream>

struct SetNode
{
	int data;
	SetNode* left;
	SetNode* right;

	SetNode(int data, SetNode* left = nullptr, SetNode* right = nullptr)
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

class SetBST
{
public:
	SetBST();
	~SetBST();

	void add(int n);
	int findMin() const;
	int findMax() const;
	bool contains(int n) const;
	void remove(int n);
	
	int getSize() const;
	bool isEmpty() const;
	friend std::ostream& operator<<(std::ostream& out, SetBST& set);

private:
	SetNode* root;
	int size;

private:
	void postOrderClear(SetNode* node);
	int findMinHelper(SetNode* node) const;
	int findMaxHelper(SetNode* node) const;
	bool containsHelper(int value, SetNode* node) const;
	//Uses ref to a pointer
	void addHelper(int value, SetNode*& node);
	void removeHelper(int value, SetNode*& node);

	void inOrderTraversal(std::ostream& out, SetNode* node, int max);
};
