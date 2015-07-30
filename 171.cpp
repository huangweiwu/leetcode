class Solution {
public:
    int titleToNumber(string s) {
		int ret = 0;
		int len = s.length();
		for(int i=len - 1; i>=0; i--) {
			ret += (s[i] - 'A' + 1) * pow(26, len - i - 1);
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
	int a[6] = {2, 3, 1, 2, 4, 8};
	vector<int> v(a, a+6);
	
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