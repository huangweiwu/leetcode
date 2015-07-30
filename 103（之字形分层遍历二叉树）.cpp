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

// 之字形遍历二叉树
//	在前面的分层遍历基础上，加个判断
//		判断当前行是在第几行，偶数行则将该行对应的vector倒置即可

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
		vector<vector<int> > ret;
		ret.clear();
		if(root == NULL)
			return ret;
		int count = 1;
		q.push(root);
		vector<int> v;
		int i=1;
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
			if(!(i & 0x01))
				reverse(v.begin(), v.end());
			i++;
			ret.push_back(v);
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
	head1->left = new TreeNode(2);
	head1->right = new TreeNode(2);
	head1->right->left = new TreeNode(4);
	head1->right->right = new TreeNode(5);
	
	
	
	system("pause");
	return 0;
}