// 给定一组由A/C/G/T组成的DNA序列，从中找到所有出现两次以上的长度为10的DNA序列
//	思路：
//		使用哈希表来保存已经出现过的字符串，map<string, int>使用空间大，因此将string转化为int，
//		A/C/G/T - 'A' + 1，分别为1/3/7/20，%5分别为1/3/2/0，因此两位即可保存这里20位即可保存一个长度为10的string

//	可进一步优化的：用一个char数组来计数，但是记住不能每次都自加，因为如果有的字符串出现了256次以上，会超出表示范围

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<int, int> m;
		vector<string> ret;
		int hashNum = 0;
		for(int i=0; i<9; i++)
			hashNum = (hashNum << 2) | ((s[i] - 'A' + 1) % 5);
		for(int i=9; i<s.length(); i++) {
			hashNum = (hashNum << 2 & 0x000FFFFF) | ((s[i] - 'A' + 1) % 5);
			if(m[hashNum]++ == 1)
				ret.push_back(s.substr(i-9, 10));
		}
		return ret;
    }
};

int main() {
	Solution so;
	so.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {3, 2, 6, 5, 0, 3};
	vector<int> v(a, a+6);
	
	system("pause");
	return 0;
}