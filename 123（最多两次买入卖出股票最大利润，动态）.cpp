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

// 给定一个一维数组，代表一支股票每一天的价格，最多可以进行两次交易，即两次买入两次卖出；求最大收益
//	思路：
//		动态规划，保存两个数组，dp1[len]和dp2[len]，dp1[i]和dp2[i]分别表示截止下标i为止，右边和左边所能达到的最大利润
//		最后对dp1[i] + dp2[i]取最大值

//	注意：买和卖可以在同一天

class Solution {
public:
    int maxProfit(vector<int>& prices) {
		if(prices.size() < 2)
			return 0;
		int len = prices.size();

		int* dp1 = new int[len];
		int* dp2 = new int[len];

		// 先求dp1
		int minprice = prices[0];
		dp1[0] = 0;
		for(int i=1; i<len; i++) {
			minprice = min(minprice, prices[i]);
			dp1[i] = max(dp1[i-1], prices[i] - minprice);
		}

		// 再求dp2
		int maxprice = prices[len-1];
		dp2[len-1] = 0;
		for(int j=len-2; j>=0; j--) {
			maxprice = max(maxprice, prices[j]);
			dp2[j] = max(dp2[j+1], maxprice - prices[j]);
		}

		int ret = 0;
		for(int i=0; i<len; i++)
			ret = max(ret, dp1[i] + dp2[i]);

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
	int a[7] = {1, 2, 3, 5, 1, 7, 9};
	vector<int> v(a, a+7);
	cout << so.maxProfit(v) << endl;
	
	system("pause");
	return 0;
}