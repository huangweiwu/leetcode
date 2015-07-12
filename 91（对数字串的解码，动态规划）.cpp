#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include <stdint.h>
using namespace std;

// A-Z对应1-26，给定一个数字组成的字符串，将其解码成A到Z
//	解码规则，12可以解码成AB或者L，求所有可能解码的方式的总数
//	思路：动态规划
//		dp[i]表示str(0...i)可能解码的方式总数，则
//		若str[i-1, i].num() > 26，则dp[i] = dp[i-1]
//		若str[i-1, i].num() <= 26，则dp[i] = dp[i-1] + dp[i-2]
//		要考虑进0的情况，0是不可能单独解码的

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int numDecodings(string s) {
		if(s.length() == 0)
			return 0;
		if(s[0] == '0')
			return 0;
		int* dp = new int[s.length()+1];
		dp[0] = 1;
		dp[1] = 1;
		for(int i=2; i<=s.length(); i++) {
			dp[i] = (s[i-1] == '0') ? 0 : dp[i-1];
			dp[i] = ((s[i-2] == '1' && s[i-1] <= '9') || (s[i-2] == '2' && s[i-1] <= '6')) ? dp[i] + dp[i-2] : dp[i];
		}
		return dp[s.length()];
    }
};

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(4);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(2);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(2);

	string s = "1214";
	int a[3] = {1, 2, 2};
	vector<int> v(a, a+3);
	cout << so.numDecodings(s);
	
	system("pause");
	return 0;
}