#include<iostream>
#include<vector>
#include<set>
#include<string>
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

// 给定一个字符串，判断其是否为回文
//	思路：
//		维持两个指针，一个向前，一个向后即可

class Solution {
public:
    bool isPalindrome(string s) {
		if(s.length() == 0)
			return true;
		int forward = 0;
		int backward = s.length() - 1;
		while(forward < backward) {
			while(forward<s.length() && !isalpha(s[forward]) && !isalnum(s[forward]))
				forward++;
			while(backward>=0 && !isalpha(s[backward]) && !isalnum(s[backward]))
				backward--;
			if(forward < backward) {
				int diff = abs(s[forward] - s[backward]);
				if(diff != 0 && diff != 32)
					return false;
				forward++;
				backward--;
			}
		}
		return true;
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
	string s = "1a2";
	cout << so.isPalindrome(s);
	
	system("pause");
	return 0;
}