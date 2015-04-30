//有一个单链表，遍历一遍删除离结尾节点距离为n的节点，并返回头结点
//重点：仅遍历一遍
//双指针思想，两个指针相隔n-1，每次两个指针向后一步，当后面一个指针没有后继了，前面一个指针就是要删除的节点


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
		if(head == NULL)
			return NULL;

		ListNode* p_pre = NULL;
        ListNode* p = head;
		ListNode* q = head;
		for(int i=0; i<n-1; i++)
			//p和q相隔n-1个节点
			q = q->next;
		while(q->next) {
			p_pre = p;
			p = p->next;
			q = q->next;
		}
		if(p_pre == NULL) 
			//要删除的节点是头节点
			head = head->next;
		else
			p_pre->next = p->next;
		return head;
    }
};