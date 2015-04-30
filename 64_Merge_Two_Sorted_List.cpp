//合并两个已经排好序的链表
//思路：
//先确定头结点，再遍历两个链表，将较小的元素作为后缀，直到其中一个链表为空
//将不为空的链表接到已经排好序的结果链表后面即可

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if(l1==NULL || l2==NULL) {
			if(l1 != NULL)
				return l1;
			else 
				return l2;
		}
		ListNode *result;
		ListNode *tmp;
		if(l1->val < l2->val) {
			result = tmp = l1;
			l1 = l1->next;
		}
		else {
			result = tmp = l2;
			l2 = l2->next;
		}
		while(l1 && l2) {
			if(l1->val < l2->val) {
				tmp->next = l1;
				tmp = tmp->next;
				l1 = l1->next;
			}
			else {
				tmp->next = l2;
				tmp = tmp->next;
				l2 = l2->next;
			}
		}
		if(l1)
			tmp->next = l1;
		if(l2)
			tmp->next = l2;
		return result;
    }
};