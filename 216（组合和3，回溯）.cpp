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

// 给定一个数n，求k个数和为n的所有组合，组合必须是单调递增的（确保唯一性）
//	思路：回溯法
//		用tmpsum保存当前选中的数的和，num表示选中的数的个数；i遍历的区间为[1, n / k)
//		中间两步判断是为了加速的

class Solution {
public:
	void backTrack(int k, int n, int tmpnum, int tmpsum, int num, vector<vector<int> >& ret, vector<int>& tmp) {
		if(tmpsum == n && num == k) {
			ret.push_back(tmp);
			return;
		}
		for(int i=tmpnum; i<10; i++) {
			tmpsum += i;
			num++;
			if(tmpsum > n)
				return;
			if(tmpsum < n && num == k) {
				num--;
				tmpsum -= i;
				continue;
			}
			tmp.push_back(i);
			backTrack(k, n, i+1, tmpsum, num, ret, tmp);
			tmpsum -= i;
			num--;
			tmp.pop_back();
		}
	}

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int> > ret;
		vector<int> tmp;
		backTrack(k, n, 1, 0, 0, ret, tmp);
		return ret;
    }
};



int main() {
	Solution so;

	so.combinationSum3(2, 18);

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
	
	system("pause");
	return 0;
}