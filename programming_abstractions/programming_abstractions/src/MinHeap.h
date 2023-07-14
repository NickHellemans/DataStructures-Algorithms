#pragma once
#include <ostream>

class MinHeap
{
public:
	MinHeap();
	~MinHeap();

	void insert(int value);
	int pop();
	friend std::ostream& operator<<(std::ostream& out, const MinHeap& heap);

private:
	int* elements;
	int size;
	int capacity;

	int parent(int idx);
	int leftChild(int idx);
	int rightChild(int idx);

	void heapifyUp(int idx);
	void heapifyDown(int idx);

	void heapifyUpIter(int idx);
	void enlarge();
};
