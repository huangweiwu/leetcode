#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
using namespace std;

// 给定一组数据，表示n个家庭的财富，第i和第i-1个家庭相邻；一个小偷进行偷窃，且不能偷相邻家庭的财产，求最大能偷得多少
// 思路：动态规划
//	dp[i]表示从第1家到第i家能偷到的最大值，且第i家必须得包含在里面，则
//	dp[i] = max(dp[i-3], dp[i-2]) + nums[i]，因此dp[i-1]中包含第i-1家的财产，而又不能偷相邻的，所以dp[i]与dp[i-1]没关系
//	初值：dp[0] = 0;	dp[1] = nums[0];	dp[2] = max(nums[0], nums[1])
//		最终结果ret = max(dp[len], dp[len-1])，因为有可能是偷到倒数第一家或者最后一家得到最大值


class Solution {
public:
    int rob(vector<int>& nums) {
		if(nums.empty())
			return 0;
		if(nums.size() == 1)
			return nums[0];
		int len = nums.size();
		int* dp = new int[len + 1];
		dp[0] = 0;
		dp[1] = nums[0];
		dp[2] = nums[1];
		for(int i=3; i<=len; i++)
			dp[i] = max(dp[i-3], dp[i-2]) + nums[i-1];
		return max(dp[len-1], dp[len]);
    }
};


int main() {
	int a[] = {1, 3, 1};
	vector<int> v(a, a+3);
	Solution so;
	cout << so.rob(v);

	system("pause");
	return 0;
}