#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include<map>
#include <stdint.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 给定一组无序数，求其中连续数字的最长长度
//	思路：用一个unordered_set s数据结构存储，遍历到一个数，将其在s中删除，同时查找其在s中连续位置的其他值，记录长度，将其他值也删除
//		这样就能快速定位到某个元素所在的最长区间的长度了

//	要点：unordered_set是一个散列集合类，不同于set用二叉树实现，这里用散列表实现
//		能快速根据值检索元素

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		unordered_set<int> s(nums.begin(), nums.end());
		int ret = 0;
		for(int n : nums) {
			if(s.find(n) == s.end())
				continue;
			s.erase(n);
			int prev = n - 1;
			int next = n + 1;
			while(s.find(prev) != s.end())
				s.erase(prev--);
			while(s.find(next) != s.end())
				s.erase(next++);
			ret = max(ret, next - prev + 1);
		}
		return ret;
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