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

// 找到一个数组中第k大的数
//	思路：快排
//		以nums[start]为基准，比它大的都放左边，比它小的都放右边

class Solution {
public:
	int partition(vector<int>& nums, int start, int end) {
		if(start == end)
			return start;
		int i = start, j = start + 1;		// i保存比num[start]大的数中最右边的数的下标
		while(j <= end) {
			if(nums[j] > nums[start]) {
				i++;
				swap(nums[i], nums[j]);
			}
			j++;
		}
		swap(nums[i], nums[start]);
		return i;
	}

    int findKthLargest(vector<int>& nums, int k) {
		int start = 0, end = nums.size() - 1;
		int par = partition(nums, start, end);
		while(par+1 != k) {
			if(par < k)
				start = par + 1;
			if(par > k)
				end = par - 1;
			par = partition(nums, start, end);
		}
		return nums[par];
    }
};



int main() {
	Solution so;

	so.combinationSum3(2, 18);

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