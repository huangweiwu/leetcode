// 给定一个字符串，返回将其分割成回文字符串组合的最小切割数
//	思路：
//		动态规划，dp[i]表示s[0...i]最小几次切割可以将其切割为回文字符串组合
//		则当遍历到s[i]，考虑s[j...i]是否是回文，是的话，dp[i] = min{dp[i], dp[j-1] + 1}
//		时间复杂度太高，要进行多次的isPalindrome判断

class Solution {
public:
	bool isPalindrome(string s, int start, int end) {
		if(start >= end)
			return true;
		while(start < end) {
			if(s[start] != s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
    int minCut(string s) {
		if(s.length() <= 1)
			return 0;
		int* dp = new int[s.length() + 1];
		dp[0] = -1;
		dp[1] = 0;
		for(int i=2; i<=s.length(); i++) {
			dp[i] = i - 1;
			for(int j=0; j<i-1; j++) {
				if(isPalindrome(s, j, i-1)) {
					dp[i] = min(dp[i], dp[j] + 1);
					break;
				}
			}
		}
		return dp[s.length()];
    }
};

// 使用一个数组表示s[j...i]是否回文，空间换时间
class Solution {
public:
    int minCut(string s) {
		if(s.length() <= 1)
			return 0;
		int* dp = new int[s.length() + 1];
		dp[0] = -1;
		dp[1] = 0;
		vector<vector<bool>> flag(s.length(), vector<bool>(s.length()+1, false));	// flag[j][i]表示s[j...i-1]是否回文

		for(int i=2; i<=s.length(); i++) {
			dp[i] = i - 1;
			for(int j=i-1; j>=0; j--) {
				if(s[j] == s[i-1] && (i-j <= 2 || flag[j+1][i-1])) {
					flag[j][i] = true;
					dp[i] = min(dp[i], dp[j] + 1);
				}
			}
		}
		return dp[s.length()];
    }
};