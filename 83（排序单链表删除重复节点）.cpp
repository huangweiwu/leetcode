#include<iostream>
#include<map>
using namespace std;

// 从排好序的链表中删除重复元素，且保留重复元素中的一个
// 遍历链表，保存前一个元素，若当前元素与前一个元素值相等，则删除

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* deleteDuplicates(ListNode* head) {
			if(head == NULL || head->next == NULL)
				return head;
			ListNode* pre = head;
			ListNode* cur = head->next;
			while(cur->next != NULL) {
				while(cur->next !=NULL && cur->val == pre->val) {
					pre->next = cur->next;
					cur = pre->next;
				}
				if(cur->next == NULL)
					break;
				pre = pre->next;
				cur = cur->next;
			}
			// 判断最后一个节点
			if(cur->val == pre->val)
				pre->next = NULL;
			return head;
		}
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(2);
	head->next->next->next = new ListNode(3);
	head->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next = new ListNode(3);
	
	Solution so;
	head = so.deleteDuplicates(head);
	while(head != NULL) {
		cout << head->val << endl;
		head = head->next;
	}
	
	return 0;
}