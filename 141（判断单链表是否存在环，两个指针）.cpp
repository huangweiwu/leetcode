struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 给定一个链表，判断其中是否有环，要求不使用额外空间
//	思路：
//		两个指针，一个每次往前移动两步，一个每次往前一次一步
//		判断这两个指针是否相等，是的话返回true

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr)
			return false;
		ListNode* headTwo = head;
		while(head != nullptr) {
			head = head->next;
			if(headTwo->next != nullptr && headTwo->next->next != nullptr)
				headTwo = headTwo->next->next;
			else
				// 能够到一个结点的next域为空，则说明无环
				return false;
			if(head == headTwo)
				return true;
		}
		return false;
    }
};