#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 给定一棵二叉树，实现hasNext()和next()函数，分别用来判断是否有下一个结点以及输出下一个结点的值
//	要求：时间复杂度O(1)，空间复杂度O(h)，h为树的高度
//	思路：
//		用一个栈s存储深度优先遍历的所有点
//		初始化将进行左孩子的深度优先遍历
//		判断是否为空，只需要判断s是否为空
//		返回next()，则用前序遍历的思路；将当前结点的右子树中向左遍历的结点入栈，然后返回当前结点值

class BSTIterator {
public:
	stack<TreeNode*> s;
    BSTIterator(TreeNode *root) {
        while(root != nullptr) {
			s.push(root);
			root = root->left;
		}
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
		return !s.empty();
    }

    /** @return the next smallest number */
    int next() {
		TreeNode* cur = s.top();
		int ret = cur->val;
		s.pop();
		if(cur->right != nullptr) {
			cur = cur->right;
			while(cur != nullptr) {
				s.push(cur);
				cur = cur->left;
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

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {3, 30, 34, 5, 9, 1};
	vector<int> v(a, a+6);

	cout << so.largestNumber(v);
	
	system("pause");
	return 0;
}