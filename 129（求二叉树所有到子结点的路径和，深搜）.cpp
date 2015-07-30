#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include<map>
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

// 给定一棵二叉树，树中结点只包含0-9的值，每一条路径代表一个数，求所有数之和
//	思路：
//		深搜，到每个叶子结点保存路径所代表的值

class Solution {
public:
	void sumNumbers(TreeNode* root, int value, vector<int> &nums) {
		if(root->left == nullptr && root->right == nullptr) {
			value *= 10;
			value += root->val;
			nums.push_back(value);
			return;
		}
		value *= 10;
		value += root->val;
		if(root->left != nullptr)
			sumNumbers(root->left, value, nums);
		if(root->right != nullptr)
			sumNumbers(root->right, value, nums);
	}

    int sumNumbers(TreeNode* root) {
        if(root == nullptr)
			return 0;
		vector<int> nums;
		nums.clear();
		sumNumbers(root, 0, nums);
		int ret = 0;
		for(int i=0; i<nums.size(); i++)
			ret += nums[i];
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
	head1->left = new TreeNode(2);
	head1->right = new TreeNode(2);
	//head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	cout << so.sumNumbers(head1);
	
	
	system("pause");
	return 0;
}