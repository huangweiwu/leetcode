//有k个排好序的单链表，将其合并成一个排好序的单链表
//思路：分治法，即先将k个列表分成两个子任务，然后递归求子任务，最后回溯
//两个单链表l1/l2的合并问题：不同于两个数组的合并，因为最终只需要返回一个头结点
//可以先定义一个结点result指向l1，遍历两个单链表，并记录当前的位置cur
//最终刚返回result->next
//因此在比较的过程中，如果l1的值比较小，只需要将l1往后移动；如果l2的值比较小，则需要将l2插入到l1中
//最后如果l1空了l2没空，则需要将l2接到l1后面；如果l1没空而l2空了，则不需要进行任何操作


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *merge2Lists(ListNode *l1, ListNode *l2) {
		//合并两个列表
		ListNode *result = new ListNode(0);
		result->next = l1;
		ListNode *cur = result;
		while(l1!=NULL && l2!=NULL) {
			if(l1->val < l2->val)
				//l1的值小于l2的值，只需要将l1往后移动
				l1 = l1->next;
			else {
				//l1的值大于l2的值，则需要将l2插入到l1中去，同时l2往后移动
				ListNode *l2_next = l2->next;
				cur->next = l2;
				l2->next = l1;
				l2 = l2_next;
			}
			cur = cur->next;
		}
		//由于cur一直指向的而是l1中的节点，所以如果l1没空而l2空了不需要进一步操作
		//而如果l2没空，则必须将cur的next指向当前l2的节点
		if(l2 != NULL)
			cur->next = l2;
		return result->next;
	}
	ListNode *mergeKLists_help(vector<ListNode *> &lists, int l, int r) {
		//递归合并
		if(l < r) {
			int m = (l+r) / 2;
			return merge2Lists(mergeKLists_help(lists, l, m), mergeKLists_help(lists, m+1, r));
		}
		return lists[l];
	}
    ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.size() == 0)
			return NULL;
		return mergeKLists_help(lists, 0, lists.size()-1);
    }
};



//另一种方法采用堆的方式，构建一个k个元素组成的小顶堆，每次返回堆顶元素，并将其后继插入堆中
//每个元素都得遍历，且插入堆的复杂度为log(k)，因此整个算法的复杂度为nklog(k)

//实现过程中需要注意的问题
//1） C++中的priority_queue默认是大顶堆，要构造小顶堆需要自己写比较函数，比较函数需要放在衣一个结构体内
//2） 堆的初始构造以及入堆出堆操作
//这个方法需要构造一个堆，造成错误：Memory Limit Exceeded
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct cmp {
	bool operator() (ListNode *a, ListNode *b) {
		return a->val > b->val;
	}
};

class Solution {
public:
	ListNode *mergeKLists(vector<ListNode *> &lists) {
		if(lists.size() == 0)
			return NULL;
		priority_queue<ListNode *, vector<ListNode *>, cmp> heap;
		for(int i=0; i<lists.size(); i++) {
			//将所有队列的第一个元素入堆
			ListNode *node = lists[i];
			if(node != NULL)
				heap.push(node);
		}
		ListNode *result = NULL;
		ListNode *pre = result;
		while(heap.size() > 0) {
			ListNode *cur = heap.top();			//当前弹出来的节点
			if(result == NULL) {
				//如果是弹出来的第一个节点，赋为头节点
				result = cur;
				pre = result;
			}
			else
				pre->next = cur;
			pre = cur;
			if(cur->next != NULL)
				//如果弹出来的节点还有后继节点，则将其入堆
				heap.push(cur->next);
		}
		return result;
    }
};