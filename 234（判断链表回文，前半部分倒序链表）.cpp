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


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// 判断回文链表，使用O(n)时间，O(1)空间
//	思路：找到中间结点位置，然后将中间结点之前的结点插入另外一个链表；新链表与原始链表的后半部分进行比较

//	注意：要计算链表中结点个数，如果是奇数个，slow要往前移一位

class Solution {
public:
    bool isPalindrome(ListNode* head) {
		if(head == nullptr || head->next == nullptr)
			return true;
		ListNode* slow = head;
		ListNode* fast = head;

		while(fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}

		ListNode* cur = head;
		int count = 0;			// 计算链表个数
		while(head != nullptr) {
			count++;
			head = head->next;
		}
		ListNode* head1 = new ListNode(0);
		head1->next = cur;
		cur = cur->next;
		head1->next->next = nullptr;
		ListNode* tmp = nullptr;
		while(cur != slow) {
			// 将前半部分全部插入
			tmp = cur->next;
			cur->next = head1->next;
			head1->next = cur;
			cur = tmp;
		}
		cur = head1->next;
		if(count & 0x01)
			slow = slow->next;

		while(slow != nullptr) {
			if(cur->val != slow->val)
				return false;
			slow = slow->next;
			cur = cur->next;
		}
		return true;
    }
};

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	//head->next->next->next->next->next = new ListNode(6);
	so.isPalindrome(head);

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