//Definition for singly-linked list.
//注意：
//1） caryy要在cur前面计算
//2） ListNode* temp = result;要写在while循环外面

//程序看着没问题，但是提示Memory Limit Exceeded，应该是不想要重新定义result
//直接用l1或者l2来存储结果
//在将l2接到l1的后面的时候，不能简单的用它们的后继来赋值，即l1_iter = l1->next, l2_next = l2->next
//l1_next = l2_next是不能将l2接到l1后面的，它仅能改变l1_iter指针的值，而不能改变l1->next的值
//引入一个previous表示前继
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
		/*int cur = (l1->val+l2->val) % 10;
		int carry = (l1->val+l2->val) / 10;
        ListNode* result = new ListNode(cur);
		ListNode* temp = result;
		while(l1->next!=NULL || l2->next!=NULL || carry) {
			cur = carry;
			if(l1->next!=NULL) {
				l1 = l1->next;
				carry = (l1->val+cur) / 10;
				cur = (l1->val+cur) % 10;
			}
			if(l2->next!=NULL) {
				l2 = l2->next;
				carry = (l2->val+cur) / 10;
				cur = (l2->val+cur) % 10;
			}
			temp->next = new ListNode(cur);
			temp = temp->next;
		}*/
		int carry = (l1->val+l2->val) / 10;
		l1->val = (l1->val+l2->val) % 10;
		ListNode* l1_iter = l1->next;
		ListNode* l2_iter = l2->next;
		ListNode* previous = l1;
		while(l1_iter!=NULL || l2_iter!=NULL || carry) {
			int temp = carry;
			if(l1_iter==NULL && l2_iter==NULL) {
				//如果是两个链表都空了，则新建一个节点作为进位
				previous->next = new ListNode(carry);
				carry = 0;
			}
			else if(l1_iter==NULL && l2_iter!=NULL) {
				//如果是l1先空了，将l2接到l1的后面
				previous->next = l2_iter;
				l1_iter = previous->next;
				previous = previous->next;
				l2_iter = NULL;
				carry = (l1_iter->val+temp) / 10;
				l1_iter->val = (l1_iter->val+temp) % 10;
				l1_iter = l1_iter->next;
			}
			else if(l1_iter!=NULL && l2_iter==NULL) {
				//如果l1没空，l2空了，则只需考虑l1的
				carry = (l1_iter->val+temp) / 10;
				l1_iter->val = (l1_iter->val+temp) % 10;
				l1_iter = l1_iter->next;
			}
			else {
				//两个链表都还没空
				carry = (l1_iter->val+l2_iter->val+temp) / 10;
				l1_iter->val = (l1_iter->val+l2_iter->val+temp) % 10;
				previous = previous->next;
				l1_iter = l1_iter->next;
				l2_iter = l2_iter->next;
			}
		}
		return l1;
    }
};