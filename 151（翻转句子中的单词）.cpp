#include<iostream>
#include<sstream>
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


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// 翻转字符串中的单词
// 先翻转整个句子，再翻转每个单词
//	注意：清除多余的空格

class Solution {
public:
    void reverseWords(string &s) {
		// 取消首尾多余的空格
		while(s.length() > 0 && s[0] == ' ')
            s = s.substr(1, s.length() - 1);
		while(s.length() > 0 && s[s.length() - 1] == ' ')
		    s = s.substr(0, s.length() - 1);
		// 去掉中间多余的空格
		for(int i=1; i<s.length(); i++) {
			if(s[i] == ' ' && s[i+1] == ' ') {
				s.erase(s.begin() + i);
				continue;
			}
			if(s[i] == '\t') {
				s[i] = ' ';
				i--;
				continue;
			}
		}
		if(s.length() == 0)
			return;
		reverse(s.begin(), s.end());
		int start = 0;
		bool flag = false;
		for(int i=0; i<s.length(); i++) {
			if(s[i] == ' ') {
				flag = true;
				reverse(s.begin() + start, s.begin() + i);
				while(s[i] == ' ')
					i++;
				start = i;
			}
		}
		reverse(s.begin() + start, s.end());
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
	
	string s = "   a   b ";
	//int a[8] = {3, 7, 6, 4, 2, 8, 7, 3};
	int a[6] = {-1, 2, 3, 5, 6, 7};
	vector<int> v(a, a+6);
	
	so.reverseWords(s);
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