#pragma once
#include <ostream>

struct LinkedListNode
{
	int data;
	LinkedListNode* next;
	LinkedListNode(const int value)
	{
		data = value;
		next = nullptr;
	}
};
//Implement with tail?
class LinkedList
{
public:
	LinkedList();
	~LinkedList();

	void add(int value);
	void addFront(int value);
	int get(int index) const;
	int insert(int index, int value);
	bool isEmpty() const;
	void removeFront();
	void removeBack();
	void remove(int index);
	int size() const;
	bool isSorted() const;

	friend std::ostream& operator <<(std::ostream& out, const LinkedList& list);

private:
	LinkedListNode* head;
	int count;

	bool isSortedHelper(LinkedListNode* node) const;
};

