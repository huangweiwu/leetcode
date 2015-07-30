#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
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

// 给定一个一维数组，代表一支股票每一天的价格，可以买入多次，卖出多次；但是下一次买入之前得先将之前买入的卖出
//	思路：
//		贪心算法，找到每个波谷波峰，其差值之和就是最终结果
//		进一步理解，只要后一项比前一项大，其差值必然可以转换为利润

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size() == 0)
			return 0;
		int ret = 0;
		for(int i=1; i<prices.size(); i++)
			ret += prices[i] - prices[i-1] > 0 ? prices[i] - prices[i-1] : 0;
		return ret;
    }
};