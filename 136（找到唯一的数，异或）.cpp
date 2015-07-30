#include<iostream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<unordered_set>
#include<unordered_map>
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

// 给定一个数组，除了其中一个数外其他都出现两次，求那个出现一次的数，要求，线性时间，不能用多余的空间
//	思路：所有数异或，将结果保存在nums[0]

class Solution {
public:
    int singleNumber(vector<int>& nums) {
		for(int i=1; i<nums.size(); i++)
			nums[0] ^= nums[i];
		return nums[0];
    }
};
