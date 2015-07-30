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

// 对一个排好序的数组进行循环移位，移位次数不知道；找到其中最小元素
//	二分检索：
//		和二分区间的首尾元素进行比较

class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
		int end = nums.size() - 1;
		int mid = (start + end) >> 1;
		while(start < end) {
			mid = (start + end) >> 1;
			if(nums[mid] > nums[end])
				start = mid + 1;
			else if(nums[mid] < nums[end])
				end = mid;
			else
				// 当nums[mid] == nums[end]
				end--;
		}
		return nums[start];
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
	int a[6] = {4, 5, 6, 1, 2, 3};
	vector<int> v(a, a+6);
	cout << so.findMin(v);
	
	system("pause");
	return 0;
}