//给一个单链表，交换每两个相邻节点的位置，并返回头节点
//要求，不修改节点的数值，而只能修改节点本身；空间复杂度为O(1）
//思路：两个两个节点进行交换
//注意：
//1） 最前面的两个节点和后面的每两个节点的交换有所不同，必须分开处理
//2） 在后面的节点交换之前需保存上一次交换完的最后一个节点，以指向本次交换后的新节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
		if(head == NULL)
			return head;
        ListNode *cur = head;
		ListNode *temp = new ListNode(0);
		ListNode *pre;
		if(head->next != NULL) {
			//第二个节点不为空，改变两个next域，同时将头节点赋为第二个节点
			temp = head->next;				//要改变head->next，先将其保存起来，即第二个节点
			head->next = head->next->next;
			temp->next = head;
			head = temp;
			pre = temp->next;
			cur = pre->next;			//cur节点后移两位
			if(cur == NULL)
				return head;
		}
		else
			return head;
		while(cur->next != NULL) {
			//需要保存上一个节点，指向这一轮交换后的第一个节点
			temp = cur->next;
			cur->next = cur->next->next;
			temp->next = cur;
			pre->next = temp;
			pre = temp->next;
			cur = pre->next;
			if(cur == NULL)
				return head;
		}
		return head;
    }
};