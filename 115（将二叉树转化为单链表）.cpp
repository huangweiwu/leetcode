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

// 将一棵二叉树转变成链表
//	思路：

//		非递归：将当前结点右孩子指向左孩子，而当前原先的右孩子则接在左孩子的最右结点的右孩子上


class Solution {
public:
    void flatten(TreeNode* root) {
        if(root == nullptr)
			return;
		TreeNode* cur = root;
		while(cur != nullptr) {
			if(cur->left != nullptr) {
				TreeNode* preleftr = cur->left;
				while(preleftr->right != nullptr)  
					preleftr = preleftr->right;
				preleftr->right = cur->right;
				cur->right = cur->left;
				cur->left = nullptr;
			}
			cur = cur->right;
		}
    }
};

//		递归：保存前驱结点的，前序遍历二叉树；注意在遍历过程中要先将左右孩子结点保存，因为有可能改变了他们左右孩子的值

class Solution {
public:
	void flatten(TreeNode* root, TreeNode* &pre) {
		if(root == nullptr)
			return;
		if(pre != nullptr) {
			pre->right = root;
			pre->left = nullptr;
		}
		pre = root;
		TreeNode* left = root->left;
		TreeNode* right = root->right;
		if(left != nullptr)
			flatten(left, pre);
		if(right != nullptr)
			flatten(right, pre);
	}
    void flatten(TreeNode* root) {
        if(root == nullptr)
			return;
		TreeNode* pre = nullptr;
		flatten(root, pre);
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
	//head1->right->right = new TreeNode(5);
	so.flatten(head1);
	
	system("pause");
	return 0;
}