#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
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

// 求二叉树的高度
//	递归求左子树和右子树的高度

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
			return 0;
		if(root->left == NULL && root->right == NULL)
			return 1;
		return max(maxDepth(root->left)+1, maxDepth(root->right)+1);
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
	head1->right->left = new TreeNode(4);
	head1->right->right = new TreeNode(5);
	
	
	
	system("pause");
	return 0;
}