#include<iostream>
#include<map>
using namespace std;

// 从排好序的链表中删除重复元素，且有重复元素的都删除
// 本题需要考虑到情况比较多；保存头结点的前驱节点，遇到没有重复值得节点，才加在后继节点。

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
			ListNode* pre = new ListNode(0);
			ListNode* newHead = new ListNode(0);
			bool flag = true;						// 第一次加入的节点是头节点，pre和newHead的后继都要改
			while(head->next != NULL) {
				if(head->val == head->next->val) {
					// 如果遇到相等的一直遍历下去直到不相等的
					while(head->next != NULL && head->val == head->next->val) {
						head = head->next;
					}
					if(head->next == NULL) {
						if(flag == true)
							// 之前没有加入过节点，说明所有的值都是重复的
							return NULL;
						else
							// 之前有加入过，则返回头节点
							return newHead->next;
					}
					else
						head = head->next;
				}
				else {
					if(flag) {
						// 第一次，头结点
						pre->next = head;
						pre = pre->next;
						newHead->next = head;
						head = head->next;
						pre->next = NULL;			// 先将后继节点置空，等碰到下一个没有重复值的才加进来
						flag = false;
					}
					else {
						pre->next = head;
						head = head->next;
						pre = pre->next;
						pre->next = NULL;
					}
				}
			}
			if(flag) 
				return head;
			pre->next = head;
			return newHead->next;
		}
};

int main() {
	ListNode* head = new ListNode(1);
	head->next = new ListNode(1);
	head->next->next = new ListNode(1);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(2);
	head->next->next->next->next->next = new ListNode(3);
	head->next->next->next->next->next->next = new ListNode(5);
	Solution so;
	head = so.deleteDuplicates(head);
	while(head != NULL) {
		cout << head->val << endl;
		head = head->next;
	}
	
	return 0;
}