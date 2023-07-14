#pragma once
#include <ostream>

struct HashNode
{
	int data;
	HashNode* next;

	HashNode(int data = 0, HashNode* next = nullptr)
	{
		this->data = data;
		this->next = next;
	}
};
class HashSet
{
public:
	HashSet();
	~HashSet();

	void add(int value);
	void clear();
	bool contains(int value) const;
	void remove(int value);
	double loadFactor() const;
	int size() const;
	friend std::ostream& operator<<(std::ostream& out, HashSet& set);

private:
	//Array of hash node pointers
	HashNode** hashTable;
	int capacity;
	int count;

	int hashCode(int value) const;
	void rehash();
	void removeHelper(int value, HashNode*& node);
};

