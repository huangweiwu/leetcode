//爬楼梯：一共n层，每次能走1-2层，求走到顶部的不同走法总数
//思路：
//动态规划：
//dp[n] = dp[n-1] + dp[n-1];

class Solution {
public:
    int climbStairs(int n) {
        int *dp = new int[n];
		dp[0] = 1;
		dp[1] = 2;
		for(int i=2; i<n; i++)
			dp[i] = dp[i-1] + dp[i-2];
		return dp[n-1];
    }
};