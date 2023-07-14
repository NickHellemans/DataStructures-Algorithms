#include "MinHeap.h"

#include <ostream>

MinHeap::MinHeap()
	:elements(new int[10]), size(0), capacity(10)
{
}

MinHeap::~MinHeap()
{
	delete[] elements;
}

void MinHeap::insert(int value)
{
	if(size == capacity)
	{
		enlarge();
	}

	elements[size] = value;
	heapifyUp(size);
	size++;
}

int MinHeap::pop()
{
	if(size == 0)
	{
		return -1;
	}

	int out = elements[0];
	size--;
	elements[0] = elements[size];
	heapifyDown(0);
	return out;
}

int MinHeap::parent(int idx)
{
	return (idx - 1) / 2;
}

int MinHeap::leftChild(int idx)
{
	return 2 * idx + 1;
}

int MinHeap::rightChild(int idx)
{
	return 2 * idx + 2;
}

void MinHeap::heapifyUp(int idx)
{
	if (idx != 0)
	{
		int p = parent(idx);
		int parenV = elements[p];
		int v = elements[idx];
		if (parenV > v)
		{
			elements[idx] = parenV;
			elements[p] = v; 
			heapifyUp(p);
		}
	}
}

void MinHeap::heapifyUpIter(int idx)
{
	while (idx != 0)
	{
		int v = elements[idx];
		int p = parent(idx);
		int parenV = elements[p];

		//MinHeap: smaller val = stop swapping
		if(parenV < v)
		{
			break;
		}

		elements[idx] = parenV;
		elements[p] = v;
		idx = p;
	}
}

void MinHeap::heapifyDown(int idx)
{
	int lIdx = leftChild(idx);
	int rIdx = rightChild(idx);

	if(idx >= size || lIdx >= size || rIdx >= size)
	{
		return;
	}

	int lV = elements[lIdx];
	int rV = elements[rIdx];
	int v = elements[idx];

	if(lV > rV && v > rV)
	{
		elements[idx] = rV;
		elements[rIdx] = v;
		heapifyDown(rIdx);
	}
	else if (rV > lV && v > lV)
	{
		elements[idx] = lV;
		elements[lIdx] = v;
		heapifyDown(lIdx);
	}

}

void MinHeap::enlarge()
{
	int* newElements = new int[capacity * 2];

	for(int i = 0; i < size; i++)
	{
		newElements[i] = elements[i];
	}

	delete[] elements;
	elements = newElements;
	capacity *= 2;
}

std::ostream& operator<<(std::ostream& out, const MinHeap& heap)
{
	out << "[ ";
	for(int i = 0; i < heap.size; i++)
	{
		out << heap.elements[i] << " ";
	}
	out << "]" << std::endl;
	return out;
}
