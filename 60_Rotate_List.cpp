//给定一个单链表，向右循环右移k位
//思路：
//从头节点开始遍历，直到末节点，统计节点个数n
//k %= n
//求得pos = n - k，tmp即需要将其后继节点指向NULL的节点
//而末节点则指向头节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
		if(k == 0 || head == NULL)
			return head;
		int n = 0;
		ListNode *cur = head;
		while(cur != NULL) {
			n++;
			cur = cur->next;
		}
		k %= n;
		if(k == 0)
			return head;
		int pos = n - k;
		cur = head;
		for(int i=1; i<pos; i++)
			cur = cur->next;
		ListNode *tmp = cur;
		cur = cur->next;
		ListNode *result = cur;
		tmp->next = NULL;	//先将中间那个位置的后继节点置为NULL

		while(cur->next != NULL)
			cur = cur->next;
		cur->next = head;

		return result;
    }
};