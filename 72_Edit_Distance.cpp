//给定两个单词word1,word2，找到将word1转化为word2所需要的最少操作数，
//即求minimal edit distance，操作类型为以下三种
//1） 插入一个字符
//2） 删除一个字符
//3） 替换一个字符
//思路：动态规划
//dp(i, j) = min{dp(i-1, j)+1, dp(i, j-1)+1, dp(i-1, j-1)+(word1[i]==word2[j]?0:1)}
//以上分别对应删除、插入和替换操作

#define INF 1000000
class Solution {
public:
    int minDistance(string word1, string word2) {
		if(word1.length() == 0)
			return word2.length();
		if(word2.length() == 0)
			return word1.length();
		int len1 = word1.length();
		int len2 = word2.length();
		int **dp = new int*[len1+1];
		for(int i=0; i<=len1; i++)
			dp[i] = new int[len2+1];
		for(int i=0; i<=len1; i++)
			for(int j=0; j<=len2; j++)
				dp[i][j] = INF;
		dp[0][0] = 0;
		for(int i=0; i<=len1; i++) {
			for(int j=0; j<=len2; j++) {
				if(i>0)
					dp[i][j] = min(dp[i-1][j]+1, dp[i][j]);
				if(j>0)
					dp[i][j] = min(dp[i][j-1]+1, dp[i][j]);
				if(i>0 && j>0)
					dp[i][j] = min(dp[i][j], dp[i-1][j-1]+(word1[i-1]==word2[j-1]?0:1));
			}
		}
		return dp[len1][len2];
    }
};