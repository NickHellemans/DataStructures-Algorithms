#pragma once
#include <string>

class ArrayStack
{
public:
	//Constructor
	ArrayStack();
	//Destructor
	~ArrayStack();

	//member functions
	void push(int n);
	int pop();
	int peek() const;
	bool isEmpty() const;
	std::string toString() const;
	int getSize() const;
	friend std::ostream& operator <<(std::ostream& out, const ArrayStack& stack);
	
private:
	//member variables
	int* elements;
	//current elements
	int size;
	//possible amount of elements
	int capacity;

	//Expand capacity when full
	void expand();
};

