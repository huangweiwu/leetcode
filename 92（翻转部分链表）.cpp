#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include <stdint.h>
using namespace std;

// 翻转一个链表中从第m到第n个元素之间的链表
// 思路：保存开始结点的前驱结点和结束结点的后继结点，并对start到end之间的结点进行翻转

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m == n)
			return head;
		ListNode* headpre = new ListNode(0);
		ListNode* startpre = headpre;
		ListNode* start = head;
		ListNode* end = headpre;
		ListNode* endnext = head;
		headpre->next = head;
		for(int i=1; i<m; i++) {
			// 找到翻转的起始位置
			start =  start->next;
			startpre = startpre->next;
		}
		for(int i=0; i<n; i++)
			// 找到翻转的终止位置
			end = end->next;
		endnext = end->next;

		// 接下来翻转从start到end
		ListNode* pre = start;
		ListNode* cur = start->next;
		pre->next = endnext;
		while(cur != end) {
			ListNode* tmp = cur->next;
			cur->next = pre;
			pre = cur;
			cur = tmp;
		}
		cur->next = pre;
		startpre->next = cur;

		return headpre->next;
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

	ListNode* ret = so.reverseBetween(head, 1, 2);
	
	system("pause");
	return 0;
}