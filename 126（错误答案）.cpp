#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
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

// 给定两个单词startword/endword和一个词典，求词典中从startword转变成endword的最短路径长度
//	转变规则：每次只能转变一个字母，路径上的所有单词都必须在词典中
//	思路：
//		宽搜，维持一个队列，维持在词典中找到的单词；将当前单词修改其中一个字母为其他的字母，steps表示当前已经转换的步数
//		如果转换后的单词等于目标单词，则返回steps+1
//		不相等：如果在词典中，则将其加入队列，并在词典中将其删除；如果不在则直接忽略
//		知道队列为空都找不到，则返回0

//		steps初始值为1，在每次宽搜到下一层的时候steps++；判断是否到了下一层，有一个技巧，在队列中层与层的元素之间插入""
//		当到了""，说明要进入下一层了

//	保存所有的转化路径，创建一个map，对每个保存进队列的，将其前继保存下来

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, unordered_set<string>& wordDict) {
		vector<vector<string>> ret;
		ret.clear();

		int len = beginWord.size();
		if(len == 0)
			return ret;

		map<string, string> m;
		queue<string> q;
		q.push(beginWord);
		q.push("");
		int steps = 1;
		wordDict.erase(beginWord);
		wordDict.erase(endWord);
		m[beginWord] = "";
		m[""] = "";
		vector<string> tmpresult;

		if(wordDict.size() == 0) {
			// 如果词典删除两个单词后为空，判断两个单词是否只差一个字符，不是的话返回空，是的话返回这个路径
			int diff = 0;
			for(int i=0; i<len; i++) {
				if(beginWord[i] != endWord[i])
					diff++;
			}
			if(diff > 1)
				return ret;
			tmpresult.push_back(beginWord);
			tmpresult.push_back(endWord);
			ret.push_back(tmpresult);
			return ret;
		}

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
				string tt = cur;
				for(int j=0; j<26; j++) {
					char c = 'a' + j;
					swap(cur[i], c);
					if(cur == endWord) {
						m[cur] = tt;
						tmpresult.push_back(cur);
						string ttt = cur;
						while(m[ttt] != "") {
							// 将其所有前继插入
							tmpresult.push_back(m[ttt]);
							ttt = m[ttt];
						}
						reverse(tmpresult.begin(), tmpresult.end());
						ret.push_back(tmpresult);
						tmpresult.clear();
					}
					if(wordDict.find(cur) != wordDict.end()) {
						// 在词典中
						q.push(cur);
						m[cur] = tt;			// 保存前继
						wordDict.erase(cur);
					}
					swap(cur[i], c);			// 交换回来
				}
			}
		}
		if(ret.empty())
			return ret;
		int minlength = ret[0].size();
		for(int i=0; i<ret.size(); i++) {
			minlength = min(minlength, (int)ret[i].size());
		}
		vector<vector<string>> rett;
		for(int i=0; i<ret.size(); i++) {
			if(ret[i].size() == minlength)
				rett.push_back(ret[i]);
		}
		return rett;
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
	string b = "c";
	unordered_set<string> wordDict;
	wordDict.insert("a");
	wordDict.insert("b");
	wordDict.insert("c");
	//wordDict.insert("lot");
	//wordDict.insert("log");
	so.findLadders(a, b, wordDict);

	
	system("pause");
	return 0;
}