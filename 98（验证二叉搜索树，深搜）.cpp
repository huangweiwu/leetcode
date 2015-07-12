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
    bool isValidBST(TreeNode* root) {
        if(!root){
            return true;
        }
        int left, right;
        return BFSvalid(root, left, right);
    }

    bool BFSvalid(TreeNode* root, int& left, int& right){
        int l_left, l_right, r_left, r_right;
        left = root->val;
        right = root->val;
        if(root->left){
            if(!BFSvalid(root->left, l_left, l_right) || l_right >= root->val)  return false;
            left = l_left;
        }
        if(root->right){
            if(!BFSvalid(root->right, r_left, r_right) || r_left <= root->val)  return false;
            right = r_right;
        }
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