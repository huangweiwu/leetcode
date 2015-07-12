#include<iostream>
using namespace std;

// 翻转单链表
//	思路：保留前继结点、当前结点和下一个结点；将当前结点的next域置为前继结点，并将三个值重新赋值，注意赋值的顺序

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
		if(head == NULL || head->next == NULL)
			return head;
		ListNode* pre = NULL;
		ListNode* cur = head;
		ListNode* next = head->next;
		while(cur->next != NULL) {
			cur->next = pre;

			pre = cur;
			cur = next;
			next = next->next;
		}
		// 到达尾结点，将其next置为pre即可
		cur->next = pre;
		return cur;
    }
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);

	Solution so;
	head = so.reverseList(head);

	system("pause");
	return 0;
}