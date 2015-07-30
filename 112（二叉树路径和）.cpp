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

// 给定一棵二叉树和一个值sum，求是否存在一条路径使得和为sum
//	思路：深搜
//	最重要的一点判断：是否到达叶子结点了

class Solution {
public:
	bool hasPathSum(TreeNode* root, int sum, int tmpsum) {
		if(root == nullptr && tmpsum == sum)
			return true;
		if(root == nullptr && tmpsum != sum)
		    return false;
		if(root->left == nullptr && root->right == nullptr)
			return tmpsum + root->val == sum;
		bool flag = false;
		if(root->left != nullptr)
			flag = hasPathSum(root->left, sum, tmpsum+root->val);
		if(root->right != nullptr)
			flag |= hasPathSum(root->right, sum, tmpsum+root->val);
		return flag;
	}
    bool hasPathSum(TreeNode* root, int sum) {
        if(root == nullptr)
			return false;
		int tmpsum = root->val;
		if(root->left == nullptr && root->right == nullptr)
			return tmpsum == sum;
		bool flag = false;
		if(root->left != nullptr)
			flag = hasPathSum(root->left, sum, tmpsum);
		if(root->right != nullptr)
			flag |= hasPathSum(root->right, sum, tmpsum);
		return flag;
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
	//head1->right->left = new TreeNode(2);
	//head1->right->right = new TreeNode(5);
	cout << so.hasPathSum(head1, 3);
	
	system("pause");
	return 0;
}