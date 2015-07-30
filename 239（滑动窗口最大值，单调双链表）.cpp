// 给定一个数组和一个滑动窗口大小k，窗口每次往右移动1个数字，求所有的窗口的最大值
//	思路：单调队列的应用，支持三种操作，push()/pop()/max()，都是在O(1)的时间内完成
//		队列中的每个元素，以pair<val, count>存储，count为某个位置i的值val往前找比它小的元素个数
//		且那些在当前窗口中，其后面有比它大的，不用存储在队列中
//		push()操作：找到队尾比当前元素小的元素，将它们从队列中删除，并将它们的count叠加到新元素的count中，最后插入新元素
//		pop()操作：如果队首元素的count非零，则将其count自减；如果为0，则将其弹出
//		max()操作：返回队首元素值

class monoqueue {
private:
	deque<pair<int, int> > m_deque;
public:
	void push(int val) {
		int count = 0;
		while(!m_deque.empty() && m_deque.back().first < val) {
			count += m_deque.back().second + 1;					// +1表示加上当前比较的元素本身
			m_deque.pop_back();
		}
		m_deque.push_back(make_pair(val, count));
	}

	void pop() {
		if(m_deque.front().second > 0) {
			m_deque.front().second--;
			return;
		}
		m_deque.pop_front();
	}

	int max() {
		return m_deque.front().first;
	}
};

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> ret;
		if(nums.size() == 0 || k == 0)
			return ret;
		if(nums.size() == 1) {
			ret.push_back(nums[0]);
			return ret;
		}

		monoqueue m;
		for(int i=0; i<k; i++) {
			m.push(nums[i]);
		}
		ret.push_back(m.max());
		for(int i=k; i<nums.size(); i++) {
			m.pop();
			m.push(nums[i]);
			ret.push_back(m.max());
		}

		return ret;
    }
};


int main() {
	Solution so;
	
	vector<string> words;
	words.push_back("oath");
	words.push_back("eath");
	char ch1[4] = {'o','a','a','n'};
	char ch2[4] = {'e','t','a','e'};
	char ch3[4] = {'i','h','k','r'};
	char ch4[4] = {'i','f','l','v'};
	vector<char> v1(ch1, ch1 + 4);
	vector<char> v2(ch2, ch2 + 4);
	vector<char> v3(ch3, ch3 + 4);
	vector<char> v4(ch4, ch4 + 4);
	vector<vector<char>> board;
	board.push_back(v1);
	board.push_back(v2);
	board.push_back(v3);
	board.push_back(v4);
	int a[8] = {1,3,-1,-3,5,3,6,7};
	vector<int> v(a, a+8);
	so.maxSlidingWindow(v, 3);
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode* headA = new ListNode(3);
	ListNode* headB = new ListNode(2);
	headB->next = headA;
	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	//head1->left = new TreeNode(2);
	//head1->left->left = new TreeNode(2);

	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	system("pause");
	return 0;
}