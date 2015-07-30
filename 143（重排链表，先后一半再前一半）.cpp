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

// 对链表重新排序，将L0->L1->L2->...->Ln-1->Ln排序成L0->Ln->L1->Ln-1->...，要求不改变指针与值对应的关系
//	思路：
//		求出链表长度，构造一个新头结点，将链表后面的一半插入，然后再依次插入前面的一半

class Solution {
public:
    void reorderList(ListNode* head) {
		if(head == nullptr || head->next == nullptr)
			return;

		int len = 0;
		ListNode* cur = head;
		while(cur != nullptr) {
			len++;
			cur = cur->next;
		}

		cur = head;
		int i = 0;
		while(i++ < (len+1) / 2)
			cur = cur->next;

		ListNode* head1 = new ListNode(0);
		head1->next = cur;
		cur = cur->next;
		head1->next->next = nullptr;
		ListNode* tmp = nullptr;
		while(cur != nullptr) {
			// 将后半部分全部插入
			tmp = cur->next;
			cur->next = head1->next;
			head1->next = cur;
			cur = tmp;
		}

		cur = head;
		ListNode* newcur = head1;
		i = 0;
		while(i++ < (len+1) / 2) {
			// 将前半部分全部插入
			tmp = cur->next;
			cur->next = newcur->next;
			newcur->next = cur;
			newcur = newcur->next->next;
			cur = tmp;
		}
		head = head1->next;
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

	so.reorderList(head);

	

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