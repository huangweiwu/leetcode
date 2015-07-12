#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include<algorithm>
#include <stdint.h>
using namespace std;

// 给定一个字符串，只包含数字，返回所有可能的IP组合；例25525511135，返回["255.255.11.135", "255.255.111.35"]
//	思路：回溯法
//	维持三个指针，表示分割的三个位置，初始值i,j,k分别为1,2,3，每次分割判断其是否满足IP的要求，满足的话则返回
//		当k遍历到倒数第二个位置进行回溯
//		注意每一部分的长度不能超过3，且不能是有0开头长度大于1

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	string judge(string s, int i, int j, int k) {
		string ret = "";
		string str1 = s.substr(0, i);
		string str2 = s.substr(i, j-i);
		string str3 = s.substr(j, k-j);
		string str4 = s.substr(k);
		if(str1[0] == '0' && str1.length() > 1)
			return ret;
		if(str2[0] == '0' && str2.length() > 1)
			return ret;
		if(str3[0] == '0' && str3.length() > 1)
			return ret;
		if((str4[0] == '0' && str4.length() > 1) || str4.length() > 3)
			return ret;
		int a1 = atoi(str1.c_str());
		int a2 = atoi(str2.c_str());
		int a3 = atoi(str3.c_str());
		int a4 = atoi(str4.c_str());
		if(a1<=255 && a2<=255 && a3<=255 && a4<=255) {
			ret = str1 + "." + str2 + "." + str3 + "." +str4;
			return ret;
		}
		return "";
	}
    vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		ret.clear();
		if(s.length() < 4)
			return ret;
		int i, j, k;
		string str;
		for(int i=1; i<=3 && i<s.length(); i++) {
			for(int j=i+1; j<=i+3 && j<s.length(); j++) {
				for(int k=j+1; k<=j+3 && k<s.length(); k++) {
					str = judge(s, i, j, k);
					if(str != "")
						ret.push_back(str);
				}
			}
		}
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

	string s = "010010";
	vector<string> ss = so.restoreIpAddresses(s);
	
	system("pause");
	return 0;
}