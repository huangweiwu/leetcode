// 判断一个数是否happy number，happy number的定义是，将其所有位上的数平方和相加得到一个新数，对新数迭代调用该过程
// 如果最后得到的和为1，则是happy number；如果该过程终止不了，则不是
//	思路：
//		用一个二叉搜索树保存已经出现过的和数，则如果是happy number，最后肯定会得到1；不是的话，肯定会有循环的地方

class Solution {
public:
	int squareSum(int n) {
		int ret = 0;
		while(n) {
			ret += (n % 10) * (n % 10);
			n /= 10;
		}
		return ret;
	}
    bool isHappy(int n) {
        unordered_set<int> s;
		s.insert(n);
		while(1) {
			n = squareSum(n);
			if(n == 1)
				return true;
			if(s.find(n) != s.end())
				return false;
			s.insert(n);
		}
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
	int a[6] = {2, 3, 1, 2, 4, 8};
	vector<int> v(a, a+6);
	cout << so.minSubArrayLen(7, v);
	
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
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	system("pause");
	return 0;
}