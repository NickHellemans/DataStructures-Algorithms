#include "HashSet.h"

#include <complex>

HashSet::HashSet()
{
	//Use hashtable with prime number as capacity --> less collisions
	hashTable = new HashNode * [17]();
	capacity = 17;
	count = 0;
}

HashSet::~HashSet()
{
	//Free all nodes in each bucket
	clear();
	//Free table itself 
	delete[] hashTable;
	hashTable = nullptr;
}

void HashSet::add(int value)
{
	//Prevent duplicates
	if(!contains(value))
	{
		int hashIndex = hashCode(value);
		HashNode* newNode = new HashNode(value, hashTable[hashIndex]);
		hashTable[hashIndex] = newNode;
		count++;

		if(loadFactor() >= 0.75)
		{
			rehash();
		}
	}

}

void HashSet::clear()
{
	for(int i = 0; i < capacity; i++)
	{
		HashNode* curr = hashTable[i];
		while(curr != nullptr)
		{
			HashNode* trash = curr;
			curr = curr->next;
			delete trash;
		}

		hashTable[i] = nullptr;
	}
}

bool HashSet::contains(int value) const
{
	int hashIndex = hashCode(value);
	HashNode* curr = hashTable[hashIndex];
	while(curr != nullptr)
	{
		if(curr->data == value)
		{
			return true;
		}
		curr = curr->next;
	}
	return false;
}

void HashSet::remove(int value)
{
	if(contains(value))
	{
		count--;
		int hashIndex = hashCode(value);
		HashNode* curr = hashTable[hashIndex];
		HashNode* prev = nullptr;

		while (curr != nullptr && curr->data != value)
		{
			prev = curr;
			curr = curr->next;
		}
		//If 1 element
		if(prev == nullptr)
		{
			hashTable[hashIndex] = curr->next;
		}
		//More than 1 element
		else
		{
			prev->next = curr->next;
		}

		delete curr;
	}
}

double HashSet::loadFactor() const
{
	return (double) count / capacity;
}

int HashSet::size() const
{
	return count;
}

int HashSet::hashCode(int value) const
{
	return std::abs(value) % capacity;
}

void HashSet::rehash()
{
	int oldCapacity = capacity;
	HashNode** oldTable = hashTable;
	capacity *= 2;
	hashTable = new HashNode * [capacity]();

	for(int i = 0; i < oldCapacity; i++)
	{
		HashNode* curr = oldTable[i];
		while(curr != nullptr)
		{
			//Save tmp var to next node before it gets lost
			HashNode* next = curr->next;
			int hashIndex = hashCode(curr->data);
			curr->next = hashTable[hashIndex];
			hashTable[hashIndex] = curr;
			curr = next;
		}
	}
	//Only need to delete the array of pointers, not the actual nodes
	delete[] oldTable;
}

std::ostream& operator<<(std::ostream& out, HashSet& set)
{
	out << "[" << std::endl;
	for (int i = 0; i < set.capacity; i++)
	{
		out << i << " --> ";
		HashNode* curr = set.hashTable[i];
		while (curr != nullptr)
		{
			out << curr->data << " --> ";
			curr = curr->next;
		}

		out << std::endl;
	}
	out << "]";
	return out;
}
