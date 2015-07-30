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

// 给定一个递增的链表，以这个链表构造一棵高度平衡的搜索二叉树，每个结点的左子树和右子树高度差不超过1
//	思路：
//		深度优先搜索，中序遍历构造二叉树，先构造左子树，再构造根结点，最后构造右子树，自底向上

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        
    }
};

class Solution {
public:
    TreeNode* sortedListToBSTHelp(ListNode* &head, int start, int end) {
        if(start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* left = sortedListToBSTHelp(head, start, mid-1);
        TreeNode* root = new TreeNode(head->val);
        root->left = left;
        head = head->next;
        root->right = sortedListToBSTHelp(head, mid+1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        int count = 0;
        ListNode* p = head;
        while(p != NULL) {
            p = p->next;
            count++;
        }
        return sortedListToBSTHelp(head, 0, count-1);
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