#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
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

// 给定一个数组，找到最大连续乘积
//	思路：动态规划，dp[i]子数组的nums[0...i]的最大乘积
//	因为有可能是正负的，也可能是0，因此要从max*nums[i] / min*nums[i] / nums[i]三者中取最大值
//		curmax = max(curmax*nums[i], max(curmin*nums[i], (long long)nums[i]));
//		curmin = min(premax*nums[i], min(curmin*nums[i], (long long)nums[i]));

class Solution {
public:
    int maxProduct(vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int curmax = nums[0], curmin = nums[0], ret = nums[0], premax;
		for(int i=1; i<nums.size(); i++) {
			premax = curmax;			// 保存用于计算curmin
			curmax = max(curmax * nums[i], max(curmin * nums[i], nums[i]));
			curmin = min(premax * nums[i], min(curmin * nums[i], nums[i]));
			ret = max(ret, curmax);
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
	int a[6] = {3, 30, 34, 5, 9, 1};
	vector<int> v(a, a+6);
	
	system("pause");
	return 0;
}