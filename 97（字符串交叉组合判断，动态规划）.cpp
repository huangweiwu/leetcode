#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
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

// 给定字符串s1/s2/s3，判断s3是否由s1和s2 interleaving组成，即s1和s2交叉组合而成
//	思路：动态规划
//		dp[i, j]表示s3[0...i+j-1]是否可以被s1[0...i-1]和s[0...j-1]组合而成
//		dp[i, j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) || (dp[i][j-1] && s3[i+j-1] == s2[j-1])
//		dp[0, 0] = true, dp[i, 0] = (s1[i-1] == s3[i-1] && dp[i-1][0]), dp[0, j] = (s2[j-1] == s3[j-1] && dp[0][j-1])

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
		int len1 = s1.length();
		int len2 = s2.length();
		int len3 = s3.length();
		if(len1 + len2 != len3)
			return false;
		if(len1 == 0 && len2 == 0 && len3 == 0)
			return true;
		if(len1 == 0) {
			if(s2 == s3)
				return true;
			else
				return false;
		}
		if(len2 == 0) {
			if(s1 == s3)
				return true;
			else
				return false;
		}
		int** dp = new int*[len1+1];
		for(int i=0; i<=len1; i++)
			dp[i] = new int[len2+1];
		dp[0][0] = true;
		for(int i=1; i<=len1; i++)
			dp[i][0] = (s1[i-1] == s3[i-1] && dp[i-1][0]);
		for(int j=1; j<=len2; j++)
			dp[0][j] = (s2[j-1] == s3[j-1] && dp[0][j-1]); 
		for(int i=1; i<=len1; i++) {
			for(int j=1; j<=len2; j++) {
				dp[i][j] = (dp[i-1][j] && s3[i+j-1] == s1[i-1]) || (dp[i][j-1] && s3[i+j-1] == s2[j-1]);
			}
		}
		return dp[len1][len2];
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
	head1->right = new TreeNode(3);
	head1->left->left = new TreeNode(4);
	head1->left->right = new TreeNode(5);
	
	string s1 = "a";
	string s2 = "b";
	string s3 = "ab";
	so.isInterleave(s1, s2, s3);
	
	system("pause");
	return 0;
}