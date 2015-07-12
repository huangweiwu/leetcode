#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
using namespace std;

// 给定一个字符串和一组单词，判断该字符串是否能分解成该组单词
// 思路1：根据全排列对单词组进行全排列，对每一个排列进行判断，如果与源字符串相等则返回true
//		超时


class Solution1 {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		int len = wordDict.size();
		int* num = new int[len];
		vector<string> str;
		for(int i=0; i<len; i++) 
			num[i] = i;
		for(unordered_set<string>::iterator iter = wordDict.begin(); iter!=wordDict.end(); iter++)
			str.push_back(*iter);
		return PermutationRecursively(s, str, len, 0, num);
    }
	bool PermutationRecursively(string s, vector<string>& wordDict, int len, int pos, int* num) {
		if(pos == len-1) {
			string tmp = "";
			for(int i=0; i<len; i++)
				tmp += wordDict[num[i]];
			if(s == tmp)
				return true;
			else
				return false;
		}
		else {
			for(int i=pos; i<len ; i++) {
				// 第一个位置可能取所有字符
				swap(num[i], num[pos]);
			
				if(PermutationRecursively(s, wordDict, len, pos+1, num))
					return true;

				swap(num[pos], num[i]);
			}
		}
		return false;
	}
};

// 思路2：dp[i]表示源字符串s[0...i]是否可以由词典中的单词组成
//	初始值dp[0] = true，dp[i]
//	for(int j=i-1; j>=0; j--)
//		如果dp[j] = true && s[j, i-j]字符串在词典中，说明dp[j] = true
//			dp[j] = false;
//	dp[s.length()]就是返回的结果
class Solution {
public:
    bool wordBreak(string s, unordered_set<string>& wordDict) {
		vector<bool> dp(s.length() + 1, false);
		dp[0] = true;
		for(int i=1; i<=s.length(); i++) {
			for(int j=i-1; j>=0; j--) {
				if(dp[j] && wordDict.find(s.substr(j, i-j))!=wordDict.end()) {
					// 找到一种组合方式即可break
					dp[i] = true;
					break;
				}
			}
		}
		return dp[s.length()];
    }
};


int main() {
	string s = "leetcode";
	unordered_set<string> wordDict;
	wordDict.insert("code");
	wordDict.insert("leet");
	Solution so;
	cout << so.wordBreak(s, wordDict) << endl;

	system("pause");
	return 0;
}