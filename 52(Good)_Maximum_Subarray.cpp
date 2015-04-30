//找到一个整型数组中，和最大的连续子串，并返回和
//思路：dp[n]，dp[i]是以A[i]为结尾的子串的最大的和
//dp[i] = max{dp[i-1]+A[i], A[i]}

class Solution {
public:
    int maxSubArray(int A[], int n) {
		int* dp = new int[n];
		dp[0] = A[0];
		for(int i=1; i<n; i++)
			dp[i] = max(dp[i-1]+A[i], A[i]);
		int result = dp[0];
		for(int i=1; i<n; i++) {
			if(dp[i] > result)
				result = dp[i];
		}
		return result;
    }
};