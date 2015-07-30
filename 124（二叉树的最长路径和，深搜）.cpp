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

// 给定一棵二叉树，求路径最大和，路径的起点可以是任意一个结点
//	思路：
//		深搜，对每个结点，都找到其左子树和右子树的最长路径长度leftmax/rightmax，则对该结点，其最长长度为leftmax + cur->val + rightmax
//		而当前子树作为父结点的子树，其最长路径长度为max(leftmax+cur->val, rightmax+cur->val)

//	注意：对于每一个结点，都要用其leftmax + cur->val + rightmax更新ret

class Solution {
public:
	int maxPathSum(TreeNode* root, int& ret) {
		// 根据当前结点的左子树和右子树的最长路径长度更新ret，同时返回作为子树的最长路径长度
		if(root == nullptr)
			return 0;
		int leftmax = max(0, maxPathSum(root->left, ret));
		int rightmax = max(0, maxPathSum(root->right, ret));

		ret = max(ret, leftmax + root->val + rightmax);
		return max(leftmax + root->val, rightmax + root->val);
	}

    int maxPathSum(TreeNode* root) {
        if(root == nullptr)
			return 0;
		int ret = INT_MIN;
		maxPathSum(root, ret);
		return ret;
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
	int a[7] = {1, 2, 3, 5, 1, 7, 9};
	vector<int> v(a, a+7);
	cout << so.maxProfit(v) << endl;
	
	system("pause");
	return 0;
}