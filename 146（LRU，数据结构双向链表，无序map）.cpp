#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include<map>
#include <stdint.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// 实现LRU cache，get/set函数
// get(key)，如果key对应的元素存在，则将移动到最前端，同时将其返回
// set(key)	如果元素不存在，判断容量是否到了，到的了话将最久没用的删掉，同时插入新的；每到的话直接插入新的
//			如果元素存在，则更新其值，同时将其移动到最前端

//	思路：用双向链表存储<key, value>，以及用unordered_map存储<key, list::iterator>用来快速查找以及存储元素对应的迭代器
//		移动可以用双向链表的splice函数，查找用unordered_map的find函数

class LRUCache{
private:
	list<pair<int, int>> l;
	unordered_map<int, list<pair<int, int>>::iterator > cache;
	int capacity;
public:
    LRUCache(int capacity):capacity(capacity) {}
    
    int get(int key) {
		if(cache.find(key) != cache.end()) {
			l.splice(l.begin(), l, cache[key]);
			return cache[key]->second;
		}
		return -1;
    }
    
    void set(int key, int value) {
		if(cache.find(key) == cache.end()) {
			// 如果元素不存在
			if(cache.size() == capacity) {
				// 容量已满
				cache.erase(l.back().first);
				l.pop_back();
			}
			l.push_front(make_pair(key, value));
			cache[key] = l.begin();
		}
		else {
			// 如果元素存在，更新其值，将其移动到链表的最前端
			cache[key]->second = value;
			l.splice(l.begin(), l, cache[key]);
		}
    }
};

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	//head->next->next->next->next->next = new ListNode(6);

	TreeNode* head1 = new TreeNode(1);
	head1->left = new TreeNode(2);
	head1->right = new TreeNode(2);
	//head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	string s = "aabaab";
	//int a[8] = {3, 7, 6, 4, 2, 8, 7, 3};
	int a[5] = {4, 2, 3, 4, 1};
	vector<int> v(a, a+5);

	string s1 = "catsanddog";
	unordered_set<string> words;
	words.insert("cat");
	words.insert("cats");
	words.insert("and");
	words.insert("sand");
	words.insert("dog");
	//vector<string> ret = so.wordBreak(s1, words);
	
	system("pause");
	return 0;
}