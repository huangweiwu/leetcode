#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include <stdint.h>
using namespace std;

// 给定两个字符串，判断一个字符串是否另一个字符串的Scramble String
// Scramble String的意思就是，对字符串s1进行递归拆分成两部分，可以选择是否交换这两部分，从而组成新的字符串s2
//	思路：动态规划，递归的查找字符串的子字符串是否另一个字符串的子串的Scramble String，子字符串长度从1开始
//	判断依据为相同字母个数一致

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool isScramble(string s1, string s2) {
        if(s1 == s2)
			return true;
		int len = s1.length();
		int count[26] = {0};
		for(int i=0; i<len; i++) {
			count[s1[i] - 'a']++;
			count[s2[i] - 'a']--;
		}
		for(int i=0; i<26; i++) {
			if(count[i] != 0)
				// 有字母个数不同
				return false;
		}

		for(int i=1; i<len; i++) {
			if(isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i)))
				// 不交换情况下
				return true;
			if(isScramble(s1.substr(0, i), s2.substr(len-i)) && isScramble(s1.substr(i), s2.substr(0, len-i)))
				// 交换情况下
				return true;
		}
		return false;
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

	string s1 = "b";
	string s2 = "a";
	cout << so.isScramble(s1, s2);
	
	system("pause");
	return 0;
}