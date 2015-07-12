#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
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

// 判断一棵二叉树是否自对称
//	思路：遍历左子树和右子树，得到序列；判断序列的值是否相等

class Solution {
public:
	void recLR(TreeNode * root, vector<int> & temp){               
        if(root==NULL){
            temp.push_back(0);
            return;
        }
        temp.push_back(root->val);
        recLR(root->left,temp);
        recLR(root->right,temp);
    }
    void recRL(TreeNode * root, vector<int> & temp){               
        if(root==NULL){
            temp.push_back(0);
            return;
        }               
        temp.push_back(root->val);
        recRL(root->right,temp);
        recRL(root->left,temp);
    }
    bool isSymmetric(TreeNode* root) {
		vector<int> a;
        vector<int> b;

        recLR(root,a);
        recRL(root,b);
		if(equal(a.begin(), a.end(), b.begin()))
			return true;
		else
			return false;
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
	//head1->left->left = new TreeNode(4);
	//head1->left->right = new TreeNode(5);
	
	cout << so.isSymmetric(head1);
	
	
	system("pause");
	return 0;
}