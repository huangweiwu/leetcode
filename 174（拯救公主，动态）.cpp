//	思路2：动态，从最后一行往上推
//		最重要的递推公式：dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]);

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
		int row = dungeon.size();
		if(row == 0)
			return 0;
		int col = dungeon[0].size();
		if(col == 0)
			return 0;
		vector<int> dp(col);
		dp[col-1] = max(1, 1 - dungeon.back().back());
		for(int i=col-2; i>=0; i--)
			// 先求最后一行的
			dp[i] = max(1, dp[i+1] - dungeon.back()[i]);
		for(int i=row-2; i>=0; i--) {
			// 再对每一行根据前一行得到的结果和列元素进行更新
			dp[col-1] = max(1, dp[col-1] - dungeon[i].back());
			for(int j=col-2; j>=0; j--)
				dp[j] = max(1, min(dp[j], dp[j+1]) - dungeon[i][j]);
		}

		return dp[0];
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
	
	int t1[2] = {2, 1};
	int t2[2] = {1, -1};
	vector<int> v11(t1, t1+2);
	vector<int> v12(t2, t2+2);
	vector<vector<int> > v;
	v.push_back(v11);
	v.push_back(v12);
	cout << so.calculateMinimumHP(v);

	system("pause");
	return 0;
}