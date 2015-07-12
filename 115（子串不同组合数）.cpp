#include<iostream>
#include<string>
#include<queue>
using namespace std;

// 源字符串S和子字符串T，T为从S中删除0到lengthof(S)个字符得到，求T在S中不同子串的数量
// 思路：动态规划
//  dp[i][j]表示字符串T[0...j]在字符串S[0...i]不同子串的数量
//	当S[i] == T[j]，说明要将T转换成S，当前字符可以保留也可以丢弃，则dp[i][j] = dp[i-1][j] + dp[i-1][j-1];
//	当S[i] != T[j]，说明要将T转换成S，当前字符只能丢弃，则dp[i][j] = dp[i-1][j]
//	初始：dp[0][0] = 1【空变换为空，数量为1】；dp[i][0] = 1【任意字符串变换为空串，只有一种方法】；dp[0][j] = 0【空串变换为长度大于零的任意字符串，没法】

class Solution {
public:
    int numDistinct(string s, string t) {
		if(s.length() < t.length())
			return 0;
		int **dp = new int*[s.length()+1];
		for(int i=0; i<s.length()+1; i++)
			dp[i] = new int[t.length()+1];
		for(int i=0; i<s.length()+1; i++)
			dp[i][0] = 1;
		for(int j=1; j<t.length()+1; j++)
			dp[0][j] = 0;
		for(int i=1; i<s.length()+1; i++) {
			for(int j=1; j<t.length()+1; j++) {
				dp[i][j] = dp[i-1][j];
				if(s[i-1] == t[j-1])
					dp[i][j] += dp[i-1][j-1];
			}
		}
		return dp[s.length()][t.length()];
    }
};

int main() {
	Solution s;
	cout << s.numDistinct("abcabc", "abc");

	system("pause");
	return 0;
}