// 在一个二维数组中查找某个数，二维数组的特点：行列都递增
//	思路：从右上角开始查找，如果比右上角的大，则往下移一行；如果比右上角的小，则左移一列

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
		int row = matrix.size();
		if(row == 0)
			return false;
		int col = matrix[0].size();
		if(col == 0)
			return false;
		int i = 0;
		int j = col - 1;
		while(i<row && j>=0) {
			if(matrix[i][j] == target) 
				return true;
			else if(target > matrix[i][j])
				i++;
			else
				j--;
		}
		return false;
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