#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<string>
#include<string.h>
#include<unordered_set>
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

// 给定一个字符串，只有数字、加减乘除和空格，求表达式的值
//	思路：
//		在字符串的头和尾添加"+"，用一个istreamstring in对象来读取，结果为ret，当前结果为temp
//		+：ret += temp; in >> temp
//		-：ret += temp; in >> temp;	temp = -temp;
//		*:	in >> t;	temp *= t;
//		/：	in >> t;	temp /= t;
//		遇到空格直接忽略

class Solution {
public:
    int calculate(string s) {
        istringstream in('+' + s + '+');
		long long ret = 0, tempret = 0, temp = 0;
		char op;
		while(in >> op) {
			// 会自动跳过空格
			if(op == '+' || op == '-') {
				ret += tempret;
				in >> tempret;
				tempret *= 44 - op;
			}
			else {
				in >> temp;
				if(op == '*')
					tempret *= temp;
				else
					tempret /= temp;
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

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[7] = {1, 2, 3, 5, 1, 7, 9};
	vector<int> v(a, a+7);
	cout << so.maxProfit(v) << endl;
	
	system("pause");
	return 0;
}