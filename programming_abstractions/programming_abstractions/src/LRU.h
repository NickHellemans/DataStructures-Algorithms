#pragma once
#include <unordered_map>


template<typename V>
struct CacheNode
{
	V value;
	CacheNode* next;
	CacheNode* prev;

	CacheNode(V val, CacheNode* next = nullptr, CacheNode* prev = nullptr)
	{
		this->value = val;
		this->next = next;
		this->prev = prev;
	}

};

template<typename K, typename V>
class LRU
{
public:
	LRU(int capacity);
	~LRU();

	void update(K key, V val1);
	V get(K key);
	friend std::ostream& operator<< (std::ostream& out, const LRU<K,V>& cache)
	{
		out << "[ ";
		CacheNode<V>* curr = cache.head;
		while (curr != nullptr)
		{
			out << curr->value << " ";
			curr = curr->next;
		}
		out << "]";
		return out;
	}

private:
	int size;
	int capacity;
	CacheNode<V>* head;
	CacheNode<V>* tail;
	std::unordered_map<K, CacheNode<V>*> lookup;
	std::unordered_map<CacheNode<V>*, K> reverseLookup;

	void detach(CacheNode<V>* node)
	{
		if(node->prev)
		{
			node->prev->next = node->next;
		}

		if (node->next)
		{
			node->next->prev = node->prev;
		}

		if(head == node)
		{
			head = head->next;
		}

		if (tail == node)
		{
			tail = tail->prev;
		}

		//break links with current nodes, will get updated in prepend
		node->next = nullptr;
		node->prev = nullptr;

	}

	void prepend(CacheNode<V>* node)
	{
		if(head == nullptr)
		{
			head = tail = node;
		}
		else
		{
			node->next = head;
			head->prev = node;
			head = node;
		}
	}

	void trimCache()
	{
		if(size > capacity)
		{
			CacheNode<V>* tmp = tail;
			detach(tmp);
			K key = reverseLookup.at(tail);
			lookup.erase(key);
			reverseLookup.erase(tail);
			size--;
			free(tmp);
		}
	}
};

template <typename K, typename V>
LRU<K, V>::LRU(int capacity)
	:size(0), capacity(capacity), head(nullptr), tail(nullptr)
{
}

template <typename K, typename V>
LRU<K, V>::~LRU()
{
	while(head != nullptr)
	{
		CacheNode<V>* trash = head;
		head = head->next;
		delete trash;
	}
}

template <typename K, typename V>
void LRU<K, V>::update(K key, V val)
{
	CacheNode<V>* node;
	//Check existence
	if(!lookup.contains(key))
	{
		node = new CacheNode<V>(val);
		size++;
		prepend(node);
		trimCache();
		lookup.insert(std::make_pair(key, node));
		reverseLookup.insert(std::make_pair(node, key));
	}
	else
	{
		node = lookup.at(key);
		node->value = val;
		//It does exist: update to front of list with updated val
		detach(node);
		prepend(node);
	}
}

template <typename K, typename V>
V LRU<K, V>::get(K key)
{
	//Check existence
	if(lookup.contains(key))
	{
		CacheNode<V>* node = lookup.at(key);
		//Update value we found and move to front
		detach(node);
		prepend(node);
		//return out val
		return node->value;
	}

	throw "Key not found";
}

