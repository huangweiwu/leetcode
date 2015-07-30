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

// 给定一个递增的序列，以这个序列构造一棵高度平衡的搜索二叉树，每个结点的左子树和右子树高度差不超过1
//	思路：
//		深度优先搜索，每次选择中间的结点为根结点，递归构造其左孩子和右孩子

class Solution {
public:
	TreeNode* makeTree(int begin, int end, vector<int>& nums) {
		if(begin == end)
			return nullptr;
		int mid = (begin + end) >> 1;
		TreeNode* root = new TreeNode(nums[mid]);
		root->left = makeTree(begin, mid, nums);
		root->right = makeTree(mid+1, end, nums);
		return root;
	}
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int begin = 0;
		int end = nums.size();
		TreeNode* root = makeTree(begin, end, nums);
		return root;
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
	int a1[5] = {3, 2, 1};
	int a2[5] = {3, 2, 1};
	vector<int> pre(a1, a1+3);
	vector<int> in(a2, a2+3);
	
	system("pause");
	return 0;
}