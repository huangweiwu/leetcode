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

// 分层遍历二叉树
//	思路：访问过的结点存入队列，每次取出队首元素，将其左右孩子分别入队列，直到队列为空
//		由于将不同层的结点分开保存，因此需要对每层的结点个数进行计数

class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
		vector<vector<int> > ret;
		ret.clear();
		if(root == NULL)
			return ret;
		int count = 1;
		q.push(root);
		vector<int> v;
		while(!q.empty()) {
			v.clear();
			int curcount = 0;
			for(int i=0; i<count; i++) {
				TreeNode* node = q.front();
				v.push_back(node->val);
				q.pop();
				if(node->left != NULL) {
					q.push(node->left);
					curcount++;
				}
				if(node->right != NULL) {
					q.push(node->right);
					curcount++;
				}
			}
			count = curcount;
			ret.push_back(v);
		}
		reverse(ret.begin(), ret.end());
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
	head1->right->left = new TreeNode(4);
	head1->right->right = new TreeNode(5);
	so.levelOrder(head1);
	
	
	
	system("pause");
	return 0;
}