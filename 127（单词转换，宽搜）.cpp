#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
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

// 给定两个单词startword/endword和一个词典，求词典中从startword转变成endword的最短路径长度
//	转变规则：每次只能转变一个字母，路径上的所有单词都必须在词典中
//	思路：
//		宽搜，维持一个队列，维持在词典中找到的单词；将当前单词修改其中一个字母为其他的字母，steps表示当前已经转换的步数
//		如果转换后的单词等于目标单词，则返回steps+1
//		不相等：如果在词典中，则将其加入队列，并在词典中将其删除；如果不在则直接忽略
//		知道队列为空都找不到，则返回0

//		steps初始值为1，在每次宽搜到下一层的时候steps++；判断是否到了下一层，有一个技巧，在队列中层与层的元素之间插入""
//		当到了""，说明要进入下一层了

class Solution {
public:
    int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
		int len = beginWord.size();
		if(len == 0)
			return 0;

		queue<string> q;
		q.push(beginWord);
		q.push("");
		int steps = 1;
		wordDict.erase(beginWord);

		while(!q.empty()) {
			string cur = q.front();
			q.pop();
			if(cur.length() == 0) {
				// 说明到了""，要进入下一层了
				steps++;
				if(q.size() > 0)
					q.push("");
				continue;
			}
			for(int i=0; i<len; i++) {
				// 对单词的每个位置都进行交换
				for(int j=0; j<26; j++) {
					char c = 'a' + j;
					swap(cur[i], c);
					if(cur == endWord)
						return steps+1;
					if(wordDict.find(cur) != wordDict.end()) {
						// 在词典中
						q.push(cur);
						wordDict.erase(cur);
					}
					swap(cur[i], c);			//交换回来
				}
			}
		}
		return 0;
    }
};

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	//int a[7] = {1, 2, 3, 5, 1, 7, 9};
	//vector<int> v(a, a+7);

	string a = "a";
	string b = "b";
	unordered_set<string> wordDict;
	wordDict.insert("a");
	wordDict.insert("b");
	wordDict.insert("c");
	so.ladderLength(a, b, wordDict);

	
	system("pause");
	return 0;
}