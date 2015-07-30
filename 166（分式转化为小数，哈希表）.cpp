// 给定一个分子分母，将其转化成小数形式，除不尽的用循环表示
//	思路：求出整数和小数部分；小数部分对分子每次乘以10再除以分母
//		如果余为0，则除尽了
//		如果余不为0，若余已经出现过，则开始循环；否则将其存入哈希表中，对应其商在ret中的位置

class Solution {
public:
    string fractionToDecimal(int64_t n, int64_t d) {
        if(n == 0)
			// 如果除数是0
			return "0";
		string ret;
		if(n < 0 ^ d < 0)
			ret += '-';
		n = abs(n);
		d = abs(d);
		ret += to_string(n / d);
		if(n % d == 0)
			return ret;
		// 如果有小数部分
		ret += '.';
		unordered_map<int, int> map;		// 保存的是<余数，余数的位置>
		for(int64_t r = n % d; r; r %= d) {
			// 终止条件是r为0
			if(map.count(r) > 0) {
				// 遇到一个同样的余数，则说明已经到了循环部位
				ret.insert(map[r], 1, '(');
				ret += ')';
				break;
			}
			map[r] = ret.size();
			r *= 10;
			ret += to_string(r / d);
		}
		return ret;
    }
};

int main() {
	
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