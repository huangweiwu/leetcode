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

// 给定一个字符串，在该字符串前添加字符，使得它成为一个回文串，求最短的目标回文串
//	思路：
//		动态规划，flag[i][j]表示string[i...j]是否回文，求得flag[0][k]，0 <= k <= len-1，
//		从而根据falg[0][k]即可求得最短的
//		另外：flag[i][j] = flag[i+1][j-1] && string[i] = string[j]
//	注意将动态分配的数组空间减小后，数组的操作不要越界了
//		依然超了空间

class Solution {
public:
    string shortestPalindrome(string s) {
		if(s.length() <= 1)
			return s;
		int len = s.length();
		bool** dp = new bool*[len];
		for(int i=0; i<len; i++)
			dp[i] = new bool[len-i];
		for(int i=0; i<len-1; i++) {
			if(i < len-i)
				dp[i][i] = true;
			if(i < len - i - 1)
				dp[i][i+1] = (s[i] == s[i+1]);
		}
		//dp[len-1][len-1] = true;

		for(int j=2; j<len; j++) {
			for(int i=0; i<len-j-i; i++) {
				dp[i][i+j] = (dp[i+1][i+j-1] && (s[i] == s[i+j]));
			}
		}

		for(int i=len-1; i>=0; i--) {
			if(dp[0][i]) {
				string tmp = s.substr(i+1, len-i-1);
				reverse(tmp.begin(), tmp.end());
				return tmp + s;
			}
		}
    }
};

//	思路2：利用KMP算法思想
//		将s翻转拼接在s后面得到l，求该字符串的next[]数组，从而可以由next[len]得到最长的回文长度
//		减去该长度剩下的字符串翻转添加在源字符串前即可成为回文串

class Solution {
public:
    string shortestPalindrome(string s) {
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
		string l = s + "#" + rev_s + "#";

        vector<int> next(l.length(), 0);
		int k = -1, j = 0;
		next[0] = -1;
		while(j < l.length() - 1) {
			if(k == -1 || l[j] == l[k]) {
				k++;
				j++;
				next[j] = k;
			}
			else
				k = next[k];
		}
        
		return rev_s.substr(0, rev_s.length() - next[l.length() - 1]) + s;
    }
};

int main() {
	Solution so;
	cout << so.shortestPalindrome("ab");
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
	int a[6] = {3, 30, 34, 5, 9, 1};
	vector<int> v(a, a+6);
	
	system("pause");
	return 0;
}