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

// 给定一个链表，链表中的结点除了有next域，还有random域，可以指向任意一个结点；返回该链表的深度复制链表
//	思路：
//		用哈希表存储pre->random之间的一个关系，保存为(random, pre)，pre为复制链表中的前驱结点，random为原始链表中的random指向的结点
//		遍历两遍，第一遍复制结点以及next于，同时将(random, pre)保存
//		第二遍根据(random, pre)来赋random域

//	上面的做法有披露，如果有两个结点random指向同一个结点，则只保存了一个；改成链表即可

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if(head == nullptr)
			return head;
		RandomListNode* newHead = new RandomListNode(head->label);
		unordered_map<RandomListNode*, vector<RandomListNode*> > m;
		RandomListNode* cur = newHead;
		RandomListNode* cursrc = head;
		if(cursrc->random != nullptr)
			m[cursrc->random].push_back(cur);
		while(cursrc->next != nullptr) {
			cur->next = new RandomListNode(cursrc->next->label);
			if(cursrc->next->random != nullptr)
				m[cursrc->next->random].push_back(cur->next);
			cur = cur->next;
			cursrc = cursrc->next;
		}

		cur = newHead;
		cursrc = head;
		while(cursrc != nullptr) {
			if(!m[cursrc].empty()) {
				// 表明源列表中有以cursrc为random域
				for(int i=0; i<m[cursrc].size(); i++)
					m[cursrc][i]->random = cur;
			}
			cursrc = cursrc->next;
			cur = cur->next;
		}
		return newHead;
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
	//head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	string s = "aabaab";
	//int a[8] = {3, 7, 6, 4, 2, 8, 7, 3};
	int a[5] = {4, 2, 3, 4, 1};
	vector<int> v(a, a+5);

	RandomListNode* head2 = new RandomListNode(1);
	head2->next = new RandomListNode(2);
	head2->random = head2->next;
	head2->next->random = head2->next;
	so.copyRandomList(head2);
	
	system("pause");
	return 0;
}