#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include<map>
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

// 给定一个链表，判断其中是否有环，如果有环返回该环的起始结点；无环的话返回空
//	思路：
//		两个指针，一个每次往前移动两步，一个每次往前一次一步
//		判断这两个指针是否相等
//			设a为头结点到循环链表起点的长度，b为循环链表起点到相交位置的长度，c为循环链表长度减b，则
//			此时慢指针走了a + b，快指针走了a + b + b + c = a + b + a + b，从而a = c
//		因此将快指针重新赋为头结点，两结点同时走，直到相同的结点就是链表起始结点

class Solution {
public:
    ListNode* detectCycle(ListNode *head) {
        if(head == nullptr)
			return nullptr;
		ListNode* fast = head;
		ListNode* slow = head;
		while(head != nullptr) {
			slow = slow->next;
			if(fast->next != nullptr && fast->next->next != nullptr)
				fast = fast->next->next;
			else
				// 能够到一个结点的next域为空，则说明无环
				return nullptr;
			if(fast == slow) {
				fast = head;
				while(fast != slow) {
					fast = fast->next;
					slow = slow->next;
				}
				return fast;
			}
		}
		return nullptr;
    }
};

int main() {
	//Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	

	TreeNode* head1 = new TreeNode(1);
	head1->left = new TreeNode(2);
	head1->right = new TreeNode(2);
	//head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	string s = "aabaab";
	//int a[8] = {3, 7, 6, 4, 2, 8, 7, 3};
	int a[5] = {4, 2, 3, 4, 1};
	vector<int> v(a, a+5);

	string s1 = "catsanddog";
	unordered_set<string> words;
	words.insert("cat");
	words.insert("cats");
	words.insert("and");
	words.insert("sand");
	words.insert("dog");
	//vector<string> ret = so.wordBreak(s1, words);
	
	system("pause");
	return 0;
}