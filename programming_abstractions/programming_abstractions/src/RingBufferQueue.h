#pragma once
#include <string>

class RingBufferQueue
{
public:
	//Constructor
	RingBufferQueue();
	//Destructor
	~RingBufferQueue();

	//member functions
	void enqueue(int n);
	int dequeue();
	int peek() const;
	bool isEmpty() const;
	bool isFull() const;
	int getSize() const;
	friend std::ostream& operator<<(std::ostream& out, const RingBufferQueue& queue);

private:
	//member variables
	int* elements;

	//current elements
	int size;

	//possible amount of elements
	int capacity;

	//Front of queue
	int front;

	//Enlarge when full
	void enlarge();
};
