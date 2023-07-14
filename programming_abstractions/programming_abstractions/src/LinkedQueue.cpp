#include "LinkedQueue.h"

LinkedQueue::LinkedQueue()
	:front(nullptr), back(nullptr), size(0)
{
}

LinkedQueue::~LinkedQueue()
{
	while(front != nullptr)
	{
		QueueNode* trash = front;
		front = front->next;
		delete trash;
	}
}

void LinkedQueue::enqueue(int n)
{
	QueueNode* newNode = new QueueNode(n);

	if(isEmpty())
	{
		front = newNode;
		back = newNode;
	}
	else
	{
		back->next = newNode;
		back = newNode;
	}

	size++;
}

int LinkedQueue::dequeue()
{
	if(isEmpty())
	{
		throw "Queue is empty";
	}

	QueueNode* tmp = front;
	int value = front->data;
	front = front->next;
	delete tmp;

	if(front == nullptr)
	{
		back = nullptr; 
	}

	size--;
	return value;
}

int LinkedQueue::peek() const
{
	return front->data;
}

bool LinkedQueue::isEmpty() const
{
	return front == nullptr;
}

int LinkedQueue::getSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& out, const LinkedQueue& stack)
{
	out << "front: [";

	QueueNode* curr = stack.front;
	while (curr != nullptr)
	{
		out << curr->data << ", ";
		curr = curr->next;
	}
	out << "]";
	return out;
}
