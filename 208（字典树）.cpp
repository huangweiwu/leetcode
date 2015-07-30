#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include <stdint.h>
using namespace std;

// 实现字典树
//	字典树中的结点，数据成员包括本身的值，是否是单词的结尾标志，被多少单词共享（用于删除），以及其后继结点数组

class TrieNode {
public:
	char ch;
	bool isend;
	int shared;
	unordered_map<char, TrieNode*> children;
    // Initialize your data structure here.
    TrieNode():ch(' '), isend(false), shared(0) {}
	TrieNode(char ch): ch(ch), isend(false), shared(0) {}
};

class Trie {
public:
    Trie() {
        root = new TrieNode();
    }
	~Trie() {
		delete root;
	}

    // Inserts a word into the trie.
    void insert(string word) {
		if(search(word))
			// 如果找到该单词，则不用插入
			return;
		TrieNode* cur = root;
		for(auto c : word) {
			if(cur->children.find(c) == cur->children.end()) {
				TrieNode* newNode = new TrieNode(c);
				cur->children[c] = newNode;
			}
			cur = cur->children[c];
			++cur->shared;
		}
		cur->isend = true;
    }

    // Returns if the word is in the trie.
    bool search(string word) {
        TrieNode* cur = root;
		for(auto c : word) {
			if(cur->children.find(c) == cur->children.end())
				return false;
			cur = cur->children[c];
		}
		return cur->isend == true;
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    bool startsWith(string prefix) {
        TrieNode* cur = root;
		for(auto c : prefix) {
			if(cur->children.find(c) == cur->children.end())
				return false;
			cur = cur->children[c];
		}
		return true;
    }

private:
    TrieNode* root;
};

// Your Trie object will be instantiated and called as such:
// Trie trie;
// trie.insert("somestring");
// trie.search("key");

int main() {
	Trie trie;
	trie.insert("somestring");
	cout << trie.search("somestring");
	cout << trie.startsWith("some");
	
	system("pause");
	return 0;
}