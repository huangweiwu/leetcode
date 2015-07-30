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

// 一棵二叉搜索树有两个结点位置错了，将其恢复正确位置
//	思路：先找到两个位置错误的结点，将他们的值交换
//		中序遍历即可，找到两个位置错误的点；两个点有可能是相邻的，也可能不是相邻的

class Solution {
public:
	void findtwonodes(TreeNode* root, TreeNode* &n1, TreeNode* &n2, TreeNode* &prev) {
		if(root == NULL)
			return;
		findtwonodes(root->left, n1, n2, prev);
		if(prev != NULL && prev->val > root->val) {  
            n2 = root;  
            if(n1 == NULL)
                n1 = prev;
        }  
        prev=root; 
        findtwonodes(root->right,n1,n2,prev); 
	}
    void recoverTree(TreeNode* root) {
        TreeNode* node1 = NULL;
		TreeNode* node2 = NULL;
		TreeNode* prev = NULL;

		findtwonodes(root, node1, node2, prev);
		if(node1 != NULL && node2 != NULL)
			swap(node1->val, node2->val);
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
	head1->right->left = new TreeNode(2);
	//head1->right->right = new TreeNode(5);
	so.recoverTree(head1);
	system("pause");
	return 0;
}