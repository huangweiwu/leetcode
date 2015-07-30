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

// 找到一颗二叉树的最小深度
//	思路：递归查找左子树和右子树的最小高度


class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr)
			return 0;
		if(root->left == nullptr && root->right == nullptr)
			return 1;
		if(root->left != nullptr && root->right != nullptr)
			return min(minDepth(root->left), minDepth(root->right)) + 1;
		if(root->left != nullptr)
			return minDepth(root->left) + 1;
		if(root->right != nullptr)
			return minDepth(root->right) + 1;
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

	

	TreeNode* head1 = new TreeNode(3);
	//head1->left = new TreeNode(2);
	head1->right = new TreeNode(1);
	//head1->right->left = new TreeNode(2);
	//head1->right->right = new TreeNode(5);
	cout << so.minDepth(head1);
	
	system("pause");
	return 0;
}