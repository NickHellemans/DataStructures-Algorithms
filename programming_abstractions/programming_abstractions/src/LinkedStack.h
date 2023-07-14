#pragma once
#include <string>

struct StackNode
{
	int data;
	StackNode* next;

	StackNode(int data, StackNode* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

class LinkedStack
{
public:
	//Constructor
	LinkedStack();
	//Destructor
	~LinkedStack();

	//member functions
	void push(int n);
	int pop();
	int peek() const;
	bool isEmpty() const;
	int getSize() const;
	friend std::ostream& operator <<(std::ostream& out, const LinkedStack& stack);

private:
	//member variables
	StackNode* head;
	//current elements
	int size;
};



