#pragma once
#include <ostream>

struct QueueNode
{
	int data;
	QueueNode* next;

	QueueNode(int data, QueueNode* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};

class LinkedQueue
{
public:
	//Constructor
	LinkedQueue();
	//Destructor
	~LinkedQueue();

	//member functions
	void enqueue(int n);
	int dequeue();
	int peek() const;
	bool isEmpty() const;
	int getSize() const;
	friend std::ostream& operator <<(std::ostream& out, const LinkedQueue& stack);

private:
	//member variables
	QueueNode* front;
	QueueNode* back;
	//current elements
	int size;
	
};









