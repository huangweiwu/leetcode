#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<map>
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

// 给定一组正整数nums和一个和s，返回其中连续子序列和大于等于s的最小长度
//	维持两个指针start/end，求两个区间内的和tempsum，初始start = end = 0, tempsum = nums[0]
//	如果tempsum == sum，则将当前长度记录下来，两者同时往前移动
//	如果tempsum < sum，则end++
//	如果tempsum > sum，则若start == end，两者同时往前移动；若start != end，则start++

//		终止条件：end == nums.size() - 1且tempsum <= sum；时间复杂度O(n)

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
		if(nums.size() == 0)
			return 0;
		int start = 0, end = 0, len = nums.size(), tempsum = nums[0], minlen = INT_MAX;
		if(tempsum >= s)
			return 1;
		while(end != nums.size()-1 || tempsum > s) {
			if(tempsum >= s) {
				// 如果当前和大于s，则更新minlen
				minlen = min(end - start + 1, minlen);
				if(minlen == 1)
					return 1;
			}
			// 再根据当前和与s的关系来更新指针位置
			if(tempsum == s) {
				tempsum -= nums[start++];
				tempsum += nums[++end];
			}
			else if(tempsum < s) {
				tempsum += nums[++end];
			}
			else {
				if(start == end) {
					tempsum = nums[++start];
					end++;
				}
				else {
					tempsum -= nums[start++];
				}
			}
		}
		if(tempsum == s)
			minlen = min(end - start + 1, minlen);
		return minlen == INT_MAX ? 0 : minlen;
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
	cout << so.minSubArrayLen(7, v);
	
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
	
	system("pause");
	return 0;
}