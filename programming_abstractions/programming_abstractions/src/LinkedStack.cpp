#include "LinkedStack.h"
#include <iostream>

LinkedStack::LinkedStack()
	:head(nullptr), size(0)
{
}

LinkedStack::~LinkedStack()
{
	while(head != nullptr)
	{
		StackNode* trash = head;
		head = head->next;
		delete trash;
	}
}

void LinkedStack::push(int n)
{
	StackNode* newNode = new StackNode(n, head);
	head = newNode;
	size++;
}

int LinkedStack::pop()
{
	if(isEmpty())
	{
		throw "Stack is empty!";
	}

	StackNode* tmp = head;
	int value = head->data;
	head = head->next;
	delete tmp;
	size--;
	return value;
}

int LinkedStack::peek() const
{
	return head->data;
}

bool LinkedStack::isEmpty() const
{
	return head == nullptr;
}

int LinkedStack::getSize() const
{
	return size;
}

std::ostream& operator<<(std::ostream& out, const LinkedStack& stack)
{
	out << "top: [";

	StackNode* curr = stack.head;
	while(curr != nullptr)
	{
		out << curr->data << ", ";
		curr = curr->next;
	}
	out << "]";
	return out;
}
