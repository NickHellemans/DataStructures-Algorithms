#pragma once
#include <string>

struct TrieNode
{
	bool isWord;
	TrieNode* children[26];
};
class Trie
{
	static bool containsPrefix(TrieNode* node, std::string prefix)
	{
		if(node == nullptr)
		{
			return false;
		}
		else if(prefix == "")
		{
			return true;
		}
		else
		{
			char nextChar = prefix[0];
			int nextIndex = nextChar - 'a';
			return containsPrefix(node->children[nextIndex], prefix.substr(1));
		}
	}
};

