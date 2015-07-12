#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include <stdint.h>
using namespace std;

// 给定一个链表和一个值x，将比x小的值放到链表的前部，大于等于x的放到链表后部
// 思路：维持两个指针保存两个链表，分别保存两部分的值
//	注意最后合并的时候，要把两个指针的next域置为空

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
		if(head == NULL || head->next == NULL)
			return head;
		ListNode* first = NULL;
		ListNode* curf = NULL;
		bool flag1 = true;
		ListNode* second = NULL;
		ListNode* curs = NULL;
		bool flag2 = true;
		while(head != NULL) {
			if(head->val < x) {
				if(flag1) {
					first = new ListNode(0);
					first->next = head;
					curf = first->next;
					flag1 = false;
				}
				else {
					curf->next = head;
					curf = curf->next;
				}
			}
			else {
				if(flag2) {
					second = new ListNode(0);
					second->next = head;
					curs = second->next;
					flag2 = false;
				}
				else {
					curs->next = head;
					curs = curs->next;
				}
			}
			head = head->next;
		}
		if(first == NULL) {
			curs->next = NULL;
			return second->next;
		}
		else if(second != NULL) {
			curf->next = second->next;
			curs->next = NULL;
		}
		return first->next;
    }
};


int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	head = so.partition(head, 3);
	system("pause");
	return 0;
}