struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 给定一个单链表，将其排序，时间复杂度O(n logn)
//	思路：分治排序


class Solution {
public:
	ListNode* merge(ListNode* head1, ListNode* head2) {
		// 将子链表合并
		ListNode* headpre = new ListNode(0);
		ListNode* cur = headpre;
		while(head1 != nullptr || head2 != nullptr) {
			if(head1 && (!head2 || head1->val <= head2->val)) {
				// head1非空，如果head2为空，则直接插入head1，如果head2不为空，则比较两者的值
				cur->next = head1;
				cur = cur->next;
				head1 = head1->next;
			}
			if(head2 && (!head1 || head2->val < head1->val)) {
				cur->next = head2;
				cur = cur->next;
				head2 = head2->next;
			}
		}
		cur->next = nullptr;
		return headpre->next;
	}

    ListNode* sortList(ListNode* head) {
		if(head == nullptr || head->next == nullptr)
			return head;

		ListNode* fast = head->next;
		ListNode* slow = head;
		while(fast != nullptr && fast->next != nullptr) {
			slow = slow->next;
			fast = fast->next->next;
		}
		fast = slow->next;
		slow->next = nullptr;
		return merge(sortList(head), sortList(fast));
    }
};