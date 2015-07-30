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

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 给定一棵二叉树，每个结点添加一个next域，将其指向其右兄弟，没有又兄弟的赋为NULL
//	思路：
//		分层遍历；第i层的个数为2 ^ (i-1)，空间复杂度较高
//		要求空间复杂度为常量空间

//		进一步，依然采用广搜，但是不需要队列，根据next域即可进行下一行next域的赋值

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == NULL)
			return;
		queue<TreeLinkNode* > q;
		q.push(root);
		int count = 1;
		while(!q.empty()) {
			TreeLinkNode* cur = q.front();
			bool flag = cur->left != nullptr;
			if(flag) {
				q.push(cur->left);
				q.push(cur->right);
			}
			q.pop();
			for(int i=1; i<count; i++) {
				cur->next = q.front();
				cur = cur->next;
				if(flag) {
					q.push(cur->left);
					q.push(cur->right);
				}
				q.pop();
			}
			count *= 2;
		}
    }
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if(root == nullptr)
			return;
		TreeLinkNode* cur;
		while(root->left != nullptr) {
			cur = root;
			while(cur != nullptr) {
				// 对当前结点的左右孩子的next域赋值
				cur->left->next = cur->right;
				if(cur->next != nullptr)
					cur->right->next = cur->next->left;
				cur = cur->next;
			}
			root = root->left;		// root为下一层的最左边结点
		}
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
	so.connect(root);
	
	system("pause");
	return 0;
}