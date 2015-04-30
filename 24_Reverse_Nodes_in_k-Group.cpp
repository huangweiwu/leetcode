//给定一个单链表，翻转每组长度为k的中间节点的顺序，如果最后一组长度不足k，则保留其顺序
//同样的要求不能修改节点的数值，同时要求空间复杂度为O(1)
//思路：
//1） 先统计剩下的节点数是否大于k，如果不是则直接返回
//2） 对于每组k个节点，进行翻转，需要保留几个节点
//		1. 翻转后的最后一个节点last_last，以便指向下一次翻转后的第一个节点 ，last_last->next = cur
//		2. 每一组的第一个节点first，用于指向下一组的第一个节点，first->next = suc
//		3. 每一次交换完后进行上述操作后，在将last_last变为最后一个节点，即last_last = first
//3） 每组K个节点进行翻转，需要一个前继节点，一个后继节点

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
		if(head == NULL)
			return head;
		if(k==1 || k==0)
			return head;
		ListNode *result = new ListNode(0);
		result->next = head;
        ListNode *pre = new ListNode(0);
		pre->next = head;				//当前操作节点的前一个节点
		ListNode *suc = head->next;		//当前操作节点的后一个节点
		ListNode *cur = head;			//表示当前遍历到的节点
		ListNode *temp = head;			//用于统计的中间节点
		ListNode *first = head;			//每一轮需要保存第一个节点，用于交换后指向下一轮的节点
		ListNode *last_last = new ListNode(0);	//上一轮的最后一个节点，用于指向下一轮交换后的第一个节点

		//第一轮交换
		int count = 0;
		while(temp != NULL) {
			//先进行计数
			count++;
			temp = temp->next;
			if(temp==NULL && count<k)
				return result->next;
			if(count == k)
				//如果计数能达到k个，跳出循环进行交换
				break;
		}
		count--;
		while(count > 0) {
			pre = cur;
			cur = suc;
			suc = suc->next;
			cur->next = pre;
			count--;
		}
		//此时cur节点已经到达第一组的最后一个节点
		result->next = cur;
		first->next = suc;
		//更新六个节点
		pre = first;
		last_last = first;
		first = first->next;
		cur = first;
		temp = first;
		if(temp == NULL)
			return result->next;
		//将suc放在temp的判断后面是因为suc此时可能为空，如果suc为空执行下面语句则会出错
		suc = suc->next;
		
		//从第二轮开始与前面的区别就是不需要对result->next进行修改
		while(1) {
			while(temp != NULL) {
				//先进行计数
				count++;
				temp = temp->next;
				if(temp==NULL && count<k)
					return result->next;
				if(count == k)
					//如果计数能达到k个，跳出循环进行交换
					break;
			}
			count--;
			while(count > 0) {
				pre = cur;
				cur = suc;
				suc = suc->next;
				cur->next = pre;
				count--;
			}
			//此时cur节点已经到达第一组的最后一个节点
			last_last->next = cur;
			first->next = suc;
			last_last = first;
			//更新五个节点
			pre = first;
			first = first->next;
			cur = first;
			temp = first;
			if(temp == NULL)
				return result->next;
			suc = suc->next;
		}
		return result->next;
    }
};