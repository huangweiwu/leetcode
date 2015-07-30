
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 删除链表中的一个结点，只给定了要删除的结点的入口地址
//	思路：将后继结点的值赋给当前结点；同时不要忘了将后继结点的空间释放，避免造成内存泄露

class Solution {
public:
    void deleteNode(ListNode* node) {
		ListNode* next = node->next;
		*node = *node->next;
		delete next;
    }
};
