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

// 根据后序遍历序列和中序遍历徐丽构建二叉树
//	思路：深搜，在后序遍历序列中的最后一个结点即为子树的根结点；根据根结点在中序遍历序列中划分左右子树
//		划分采用STL中的find()函数
//		根结点的左孩子为左子树中的最后一个结点，右孩子为右子树中的最后一个结点

class Solution {
public:
	template<class T>
	TreeNode* makeTree(T ibegin, T iend, T pbegin, T pend) { 
		if(pbegin == pend)
			return NULL;
		if(ibegin == iend)
			return NULL;
		int val = *(pend-1);
		auto iRoot = find(ibegin, iend, val);
		TreeNode* root = new TreeNode(val);
		int leftSize = iRoot - ibegin;
		root->left = makeTree(ibegin, ibegin + leftSize, pbegin, pbegin + leftSize);
		root->right = makeTree(ibegin + leftSize + 1, iend, pbegin + leftSize, pend-1);
		return root;
	}

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		TreeNode* root = makeTree(inorder.begin(), inorder.end(), postorder.begin(), postorder.end());
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
	so.buildTree(pre, in);
	system("pause");
	return 0;
}