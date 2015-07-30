#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include <stdint.h>
using namespace std;



struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct TreeLinkNode {
	int val;
	TreeLinkNode *left, *right, *next;
	TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

// 给定一个正整数组，求由这个数组中所有的数组成的最大正整数，返回字符串
//	思路：对数组进行排序，但是排序标准不是按大小，而是按字符串的比较方式来进行

int compare(const void* num1, const void* num2) {
	int a = *(int*) num1;
	int b = *(int*) num2;
	if(a == b)
		return 0;
	stringstream ss;
	string str1, str2;
	ss << a;
	ss >> str1;
	ss.clear();
	ss << b;
	ss >> str2;
	string str3, str4;
	str3 = str1 + str2;
	str4 = str2 + str1;
	for(int i=0; i<str3.length(); i++) {
		if(str3[i] != str4[i])
			return str3[i] - str4[i];
	}
}

int compare1(int a, int b) {
	return to_string(a) + to_string(b) > to_string(b) + to_string(a);
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string ret = "";
		if(nums.size() == 0)
			return ret;
		sort(nums.begin(), nums.end(), compare1);
		for(auto n : nums)
			ret += to_string(n);
		return ret.front() == '0' ? "0" : ret;
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

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {3, 30, 34, 5, 9, 1};
	vector<int> v(a, a+6);

	cout << so.largestNumber(v);
	
	system("pause");
	return 0;
}