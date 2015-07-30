// 给定两个字符串，判断两个字符串是否格式上一致
//	思路：哈希表
//		用两个哈希表分别存储其所有字符以及字符所在的位置
//		代码中位置用的是i+1，是避免i等于0的时候map[i] = 0与没出现过i时是一样的

class Solution {
public:
    bool isIsomorphic(string s, string t) {
		if(s.length() == 0)
			return true;
		unordered_map<char, int> m1;
		unordered_map<char, int> m2;
		for(int i=0; i<s.length(); i++) {
			if(m1[s[i]] != m2[t[i]])
				return false;
			m1[s[i]] = i+1;
			m2[t[i]] = i+1;
		}
		return true;
    }
};

int main() {
	Solution so;
	
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
	int a[6] = {1, 2, 3, 4, 5};
	vector<int> v(a, a+5);
	unordered_map<char, int> m;
	
	system("pause");
	return 0;
}