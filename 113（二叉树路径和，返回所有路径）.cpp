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

// 给定一棵二叉树和一个值sum，返回所有路径和等于sum的路径
//	思路：深搜
//	最重要的一点判断：是否到达叶子结点了


class Solution {
public:
	void pathSum(TreeNode* root, int sum, int tmpsum, vector<int>& tmp, vector<vector<int > >& ret) {
		if(root->left == nullptr && root->right == nullptr && tmpsum+root->val == sum) {
			tmp.push_back(root->val);
			ret.push_back(tmp);
			tmp.pop_back();
			return;
		}
		if(root->left != nullptr) {
			tmp.push_back(root->val);
			pathSum(root->left, sum, tmpsum+root->val, tmp, ret);
			tmp.pop_back();
		}
		if(root->right != nullptr) {
			tmp.push_back(root->val);
			pathSum(root->right, sum, tmpsum+root->val, tmp, ret);
			tmp.pop_back();
		}
	}
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int> > ret;
		ret.clear();
		if(root == nullptr)
			return ret;
		int tmpsum = root->val;
		vector<int> tmp;
		tmp.push_back(tmpsum);
		if(root->left == nullptr && root->right == nullptr && tmpsum == sum) {	
			ret.push_back(tmp);
			return ret;
		}
		if(root->left != nullptr) 
			pathSum(root->left, sum, tmpsum, tmp, ret);
		if(root->right != nullptr)
			pathSum(root->right, sum, tmpsum, tmp, ret);
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
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	//head1->right->left = new TreeNode(2);
	//head1->right->right = new TreeNode(5);
	vector<vector<int> > ret =  so.pathSum(head1, 1);
	
	system("pause");
	return 0;
}