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

// 给定两个链表，找到两个链表开始相交的结点
// 要求时间复杂度为O(n)，空间复杂度为O(1)；没有相交的话返回null；且要保留链表的原始结构
//	思路：
//		先计算两个链表的长度len1/len2，然后让链表较长的先走abs(len1 - len2)步

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if(headA == nullptr || headB == nullptr)
			return nullptr;

		ListNode* cura = headA;
		ListNode* curb = headB; 
		int len1 = 0, len2 = 0;
		while(cura != nullptr) {
			cura = cura->next;
			len1++;
		}
		while(curb != nullptr) {
			curb = curb->next;
			len2++;
		}
		cura = headA;
		curb = headB;
		if(len1 > len2) {
			for(int i=0; i<len1-len2; i++)
				cura = cura->next;
		}
		else if(len2 > len1) {
			for(int i=0; i<len2-len1; i++)
				curb = curb->next;
		}

		while(cura != nullptr) {
			if(cura == curb)
				return cura;
			cura = cura->next;
			curb = curb->next;
		}
		return nullptr;
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

	ListNode* headA = new ListNode(3);
	ListNode* headB = new ListNode(2);
	headB->next = headA;
	so.getIntersectionNode(headA, headB);
	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {4, 5, 6, 1, 2, 3};
	vector<int> v(a, a+6);
	
	system("pause");
	return 0;
}