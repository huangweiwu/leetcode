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

// 判断一棵树是否二叉搜索树
// 思路：深度优先搜索，返回子树的最大值
//	同时保存左子树的左值右值以及右子树的左值右值

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
		if(p == NULL && q == NULL)
			return true;
		if((p == NULL && q != NULL) || (p != NULL && q == NULL))
			return false;
		if(p->val == q->val)
			return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
		else
			return false;
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
	
	system("pause");
	return 0;
}