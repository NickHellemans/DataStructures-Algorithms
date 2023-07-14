#include "ArrayStack.h"
#include <iostream>

ArrayStack::ArrayStack()
	:elements(new int[10]()), size(0), capacity(10)
{
}

ArrayStack::~ArrayStack()
{
	delete[] elements;
}

void ArrayStack::push(int n)
{
	if(size == capacity)
	{
		expand();
	}

	elements[size] = n;
	size++;
}

int ArrayStack::pop()
{
	//TODO check for empty stack and return error
	const int top = elements[size - 1];
	elements[size - 1] = 0; //Zero element out
	size--;
	return top;
}

int ArrayStack::peek() const
{
	//TODO check for empty stack and return error
	return elements[size - 1];
}

bool ArrayStack::isEmpty() const
{
	return size == 0;
}

std::string ArrayStack::toString() const
{
	std::string s = "{";
	for (int i = 0; i < size; i++)
	{
		s += std::to_string(elements[i]) + " ";
	}

	s += "}";

	return s;
}

int ArrayStack::getSize() const
{
	return size;
}

void ArrayStack::expand()
{
	//Create new buffer for more data
	int* newElements = new int[capacity * 2];

	//Copy old data over to new buffer
	for(int i = 0; i < size; i++)
	{
		newElements[i] = elements[i];
	}

	//Delete old buffer
	delete[] elements;

	//Set member var to new data
	elements = newElements;

	//update capacity
	capacity *= 2;
}


std::ostream& operator <<(std::ostream& out, const ArrayStack& stack)
{
	out << stack.toString();
	return out;
}
