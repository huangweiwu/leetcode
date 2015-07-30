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

// 给定一个一维数组，代表一支股票每一天的价格，要求只能买入卖出一次，求最大利润
//	思路：
//		倒序动态规划，假设第i天买入股票，则最大利润为第i+1 ~ n天的最高价减去第i天价格
//		初始最高价为maxprice = prices[len-1]，在往前递推的时候更新最大值及最大利润
//			maxprice = max(maxprice, prices[i])
//			ret = max(ret, maxprice - prices[i])

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size() == 0)
			return 0;

		int maxprice = prices[prices.size() - 1];
		int ret = 0;
		for(int i=prices.size() - 1; i>=0; i--) {
			maxprice = max(maxprice, prices[i]);
			ret = max(ret, maxprice - prices[i]);
		}
		return ret;
    }
};