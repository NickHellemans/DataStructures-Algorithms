#include "LinkedList.h"

LinkedList:: LinkedList()
{
	head = nullptr;
	count = 0;
}

LinkedList::~LinkedList()
{
	LinkedListNode* curr = head;
	while(curr != nullptr)
	{
		const LinkedListNode* trash = curr;
		curr = curr->next;
		delete trash;
	}

}

void LinkedList::add(int value)
{
	LinkedListNode* newNode = new LinkedListNode(value);

	if(head == nullptr)
	{
		head = newNode;
	}
	else
	{
		LinkedListNode* curr = head;
		while(curr->next != nullptr)
		{
			curr = curr->next;
		}
		curr->next = newNode;
	}
	count++;
}

void LinkedList::addFront(int value)
{
	LinkedListNode* newNode = new LinkedListNode(value);
	newNode->next = head;
	head = newNode;
	count++;
}

int LinkedList::get(int index) const
{
	if(index >= count)
	{
		return -1;
	}

	LinkedListNode* curr = head;
	for (int i = 0; curr && i < index; i++)
	{
		curr = curr->next;
	}

	if(curr != nullptr)
		return curr->data;

	return -1;
}

int LinkedList::insert(int index, int value)
{

	if (index == 0)
	{
		addFront(value);
		return value;
	}

	if (index == count)
	{
		add(value);
		return value;
	}

	if (index > count)
	{
		throw "Index too high!";
	}

	LinkedListNode* curr = head;
	for(int i = 0; curr && i < index - 1; i++)
	{
		curr = curr->next;
	}

	LinkedListNode* newNode = new LinkedListNode(value);
	newNode->next = curr->next;
	curr->next = newNode;
	count++;
	return value ;

}

bool LinkedList::isEmpty() const
{
	return count == 0;
}

void LinkedList::removeFront()
{
	if(head != nullptr)
	{
		const LinkedListNode* trash = head;
		head = head->next;
		delete trash;
		count--;
	}
}

void LinkedList::removeBack()
{
	if(head != nullptr)
	{
		if(head->next == nullptr)
		{
			delete head;
			head = nullptr;
		}
		else
		{
			LinkedListNode* curr = head;
			while(curr->next->next != nullptr)
			{
				curr = curr->next;
			}
			delete curr->next;
			curr->next = nullptr;
		}
		count--;
	}
}

void LinkedList::remove(int index)
{
	if (index == 0)
	{
		removeFront();
	}
	else if (index == count)
	{
		removeBack();
	}
	else
	{
		if (head != nullptr && index <= count)
		{
			LinkedListNode* curr = head;

			for(int i = 0; curr && i < index - 1; i++)
			{
				curr = curr->next;
			}

			LinkedListNode* trash = curr->next;
			curr->next = curr->next->next;
			delete trash;
		}
	}
}

int LinkedList::size() const
{
	return count;
}

bool LinkedList::isSorted() const
{
	return isSortedHelper(head);
}

bool LinkedList::isSortedHelper(LinkedListNode* node) const
{
	if(node != nullptr)
	{
		LinkedListNode* curr = head;
		while(curr->next != nullptr)
		{
			if(curr->data > curr->next->data)
			{
				return false;
			}
			curr = curr->next;
		}
	}
	return true;
}

std::ostream& operator<<(std::ostream& out, const LinkedList& list)
{
	LinkedListNode* curr = list.head;
	out << "[";
	while(curr != nullptr)
	{
		out << curr->data << " ";
		curr = curr->next;
	}
	out << "]" << std::endl;
	return out;
}
