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

// 句子根据词典拆分，同时返回所有的拆分可能
//	思路：
//		将s[0...i]的拆分结果保存；超时

class Solution {
public:
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;

		vector<string>* ret = new vector<string>[s.length() + 1];
		ret[0].push_back("");
		for(int i=1; i<=s.length(); i++) {
			for(int j=i-1; j>=0; j--) {
				if(dp[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end()) {
					// 找到一种组合方式，其之前的ret[j]中的所有元素加上s.substr(j, i-j)，插入当前的ret[i]
					dp[i] =true;
					for(int k=0; k<ret[j].size(); k++) {
						string tmp = s.substr(j, i-j);
						if(ret[j][k].length() != 0)
							tmp = ret[j][k] + " " + tmp;
						ret[i].push_back(tmp);
					}
				}
			}
		}
		return ret[s.length()];
    }
};

// 思路2：回溯，回溯也是用递归实现


class Solution {
public:
	bool isWordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for(int i=1; i<=s.length(); i++) {
			for(int j=i-1; j>=0; j--) {
				if(dp[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end()) {
					// 找到一种组合方式即可break
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.length()];
    }
	void breakWords(string s, int index, unordered_set<string>& wordDict, string sol, vector<string>& res) {
		// 回溯查找所有拆分方法，回溯也是用递归
		if (index == s.length()) {
			// 如果到了字符串末尾，将当前得到的结果入res
			sol.resize(sol.length() - 1);
			res.push_back(sol);
			return;
		}
		for(int j = index; j<s.length(); j++) {
			string word = s.substr(index, j - index + 1);
			if(wordDict.find(word) != wordDict.end()) {
				// 如果找到了，往前推
				string tmp = sol + word + " ";
				breakWords(s, j + 1, wordDict, tmp, res);
			}
		}
	}
    vector<string> wordBreak(string s, unordered_set<string>& wordDict) {
		string sol;
		vector<string> res;
		if(!isWordBreak(s, wordDict))
			return res;
		breakWords(s, 0, wordDict, sol, res);
		return res; 
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
	vector<string> ret = so.wordBreak(s1, words);
	
	system("pause");
	return 0;
}