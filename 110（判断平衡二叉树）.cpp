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

// 判断一棵二叉树是否平衡二叉树，即任意一个结点，其左子树和右子树高度差不超过1
//	思路：递归求得左子树和右子树的高度，判断其高度差；在求左右子树的高度时，若左右子树不是平衡二叉树，则返回-1；是的话返回高度


class Solution {
public:
	int isBalancedHelp(TreeNode* root) {
		if(root == NULL)
			return 0;
		int left = isBalancedHelp(root->left);
		if(left == -1)
			return -1;
		int right = isBalancedHelp(root->right);
		if(right == -1)
			return -1;

		if(abs(left - right) > 1)
			return -1;
		else
			return max(left, right) + 1;
	}

    bool isBalanced(TreeNode* root) {
		if(isBalancedHelp(root) == -1)
			return false;
		else
			return true;
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
	head1->right->right = new TreeNode(5);
	cout << so.isBalanced(head1) << endl;
	
	system("pause");
	return 0;
}