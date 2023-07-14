#include "RingBufferQueue.h"
#include <iostream>

RingBufferQueue::RingBufferQueue()
	:elements(new int[10]), size(0), capacity(10), front(0)
{
}

RingBufferQueue::~RingBufferQueue()
{
	delete[] elements;
}

void RingBufferQueue::enqueue(int n)
{
    if(isFull())
    {
        enlarge();
    }

	//Wrap around if needed
    const int tail = (front + size) % capacity;
	elements[tail] = n;
    size++;
}

int RingBufferQueue::dequeue()
{
    const int value = peek();
    front = (front + 1) % capacity;
    size--;
    return value;
}

int RingBufferQueue::peek() const
{
    if (isEmpty())
    {
        std::cout << "Queue is empty" << std::endl;
        return -1;
    }

    return elements[front];
}

bool RingBufferQueue::isEmpty() const
{
    return size == 0;
}

bool RingBufferQueue::isFull() const
{
    return size == capacity;
}

int RingBufferQueue::getSize() const
{
	return size;
}

void RingBufferQueue::enlarge()
{
    int* newElements = new int[capacity * 2];

    for(int i = 0; i < size; i++)
    {
        newElements[i] = elements[(front + i % capacity)];
    }

    delete[] elements;

    elements = newElements;
    capacity *= 2;
    front = 0;
}

std::ostream& operator<<(std::ostream& out, const RingBufferQueue& queue)
{
    out << "{";

    if (!queue.isEmpty()) {
        out << queue.elements[queue.front];
        for (int i = 1; i < queue.size; i++) {
            int index = (queue.front + i) % queue.capacity;
            out << ", " << queue.elements[index];
        }
    }

    out << "}";
    return out;
}

