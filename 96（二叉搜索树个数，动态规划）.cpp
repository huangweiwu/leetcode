#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include <stdint.h>
using namespace std;

// 给定n，求由1到n组成的二叉搜索树的个数
//	思路：动态规划
//	dp[i]保存1到i组成的二叉搜索树的个数，则dp[i] = dp[j-1] * dp[i-j];其中j从1到i
//		因为1到i组成的二叉搜索树，可以以1到i任意一个点为根结点，以j为根结点时，左子树有j-1个点，右子树有i-j个点
//		初始值dp[0] = 1, dp[1] = 1, dp[2] = 2

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

class Solution {
public:
    int numTrees(int n) {
		if(n == 0)
			return 1;
		if(n == 1)
			return 1;
		if(n == 2)
			return 2;
        int* dp = new int[n+1];
		dp[0] = dp[1] = 1;
		dp[2] = 2;
		for(int i=3; i<=n; i++)
			dp[i] = 0;
		for(int i=3; i<=n; i++) 
			for(int j=1; j<=i; j++)
				dp[i] += dp[j-1] * dp[i-j];
		return dp[n];
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
	vector<int> v = so.postorderTraversal(head1);
	
	system("pause");
	return 0;
}