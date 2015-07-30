// 给定一个0/1矩阵，返回其中小岛个数，即连续的1组成的块
//	思路：
//		深搜，每个访问过的结点，值都改成2

class Solution {
public:
	void broadcast(int i, int j, int row, int col, vector<vector<char>>& grid) {
		// 将1结点周围的1全部变为2
		if(grid[i][j] == '1') {
			grid[i][j] = '2';
			if(i > 0)
				broadcast(i - 1, j, row, col, grid);
			if(i < row - 1)
				broadcast(i + 1, j, row, col, grid);
			if(j > 0)
				broadcast(i, j - 1, row, col, grid);
			if(j < col - 1)
				broadcast(i, j + 1, row, col, grid);
		}
	}

    int numIslands(vector<vector<char>>& grid) {
		if(grid.size() == 0)
			return 0;
		int row = grid.size();
		if(grid[0].size() == 0)
			return 0;
		int col = grid[0].size();
		int ret = 0;
		for(int i=0; i<row; i++) {
			for(int j=0; j<col; j++) {
				if(grid[i][j] == '1') {
					ret++;
					broadcast(i, j, row, col, grid);
				}
			}
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