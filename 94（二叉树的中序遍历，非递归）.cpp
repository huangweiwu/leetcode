#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include <stdint.h>
using namespace std;

// 中序遍历二叉树，不用递归的方式
//	思路：用一个栈s保存根结点
//	遍历二叉树，若root非空，则将root入栈
//		若root为空，且s非空，则说明遍历到了某棵子树的最左端，将s的栈顶弹出，同时将其值赋给root
//		若root为空且s为空，说明已经遍历结束

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ret;
		ret.clear();
		if(root == NULL)
			return ret;
		stack<TreeNode* > s;
		while(root != NULL || !s.empty()) {
			if(root != NULL) {
				s.push(root);
				root = root->left;
			}
			else {
				root = s.top();
				ret.push_back(root->val);
				s.pop();
				root = root->right;
			}
		}
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

	string s = "010010";
	vector<string> ss = so.restoreIpAddresses(s);
	
	system("pause");
	return 0;
}