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

// 根据前序遍历序列和中序遍历徐丽构建二叉树
//	思路：深搜，在前序遍历序列中的第一个结点即为子树的根结点；根据根结点在中序遍历序列中划分左右子树
//		划分采用STL中的find()函数
//		根结点的左孩子为左子树中的第一个结点，右孩子为右子树中的第一个结点

//	注意：左右子树的划分

class Solution {
public:
	template<class T>
	TreeNode* makeTree(T pbegin, T pend, T ibegin, T iend) { 
		if(pbegin == pend)
			return NULL;
		if(ibegin == iend)
			return NULL;
		int val = *pbegin;
		auto iRoot = find(ibegin, iend, val);
		TreeNode* root = new TreeNode(*iRoot);
		int leftSize = iRoot - ibegin;
		root->left = makeTree(pbegin + 1, pbegin + leftSize + 1, ibegin, ibegin + leftSize);
		root->right = makeTree(pbegin + leftSize + 1, pend, ibegin + leftSize + 1, iend);
		return root;
	}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		TreeNode* root = makeTree(preorder.begin(), preorder.end(), inorder.begin(), inorder.end());
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
	int a1[5] = {2, 1, 4, 3, 5};
	int a2[5] = {1, 2, 3, 4, 5};
	vector<int> pre(a1, a1+5);
	vector<int> in(a2, a2+5);
	so.buildTree(pre, in);
	system("pause");
	return 0;
}