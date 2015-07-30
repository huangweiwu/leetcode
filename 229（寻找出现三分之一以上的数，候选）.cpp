#include<iostream>
#include<sstream>
#include<vector>
#include<set>
#include<unordered_set>
#include<string>
#include<unordered_set>
#include<unordered_map>
#include<stack>
#include<algorithm>
#include<stdarg.h>
#include<queue>
#include<map>
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

struct UndirectedGraphNode {
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};


struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

// 给定一组数，找出其中个数大于n/3的元素
//	思路：最多可能有两个
//		两轮遍历，第一轮找出可能的候选者(出现次数最多的两个）；第二轮进行验证

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
		int len = nums.size();
		int candidate1 = 0, candidate2 = 0;
		int count1 = 0, count2 = 0;
		for(int i=0; i<nums.size(); i++) {
			if(nums[i] == candidate1)
				count1++;
			else if(nums[i] == candidate2)
				count2++;
			else {
				// 如果上面两者都不等
				if(count1 && count2) {
					// 如果之前有记过数，将其自减
					count1--;
					count2--;
				}
				else if(count1) {
					candidate2 = nums[i];
					count2++;
				}
				else {
					candidate1 = nums[i];
					count1++;
				}
			}
		}
		vector<int> candidate;
		if(count1)
			candidate.push_back(candidate1);
		if(count2)
			candidate.push_back(candidate2);
		
		vector<int> ret;
		for(int i=0; i<candidate.size(); i++) {
			// 验证
			int count = 0;
			for(int j=0; j<len; j++) {
				if(nums[j] == candidate[i])
					count++;
			}
			if(count > len / 3)
				ret.push_back(candidate[i]);
		}
		return ret;
    }
};

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	//head->next->next = new ListNode(3);
	//head->next->next->next = new ListNode(4);
	//head->next->next->next->next = new ListNode(5);
	//head->next->next->next->next->next = new ListNode(6);

	TreeNode* head1 = new TreeNode(1);
	head1->left = new TreeNode(2);
	head1->right = new TreeNode(2);
	//head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	
	string s = "   a   b ";
	//int a[8] = {3, 7, 6, 4, 2, 8, 7, 3};
	int a[6] = {-1, 2, 3, 5, 6, 7};
	vector<int> v(a, a+6);
	
	so.reverseWords(s);
	string s1 = "catsanddog";
	unordered_set<string> words;
	words.insert("cat");
	words.insert("cats");
	words.insert("and");
	words.insert("sand");
	words.insert("dog");
	//vector<string> ret = so.wordBreak(s1, words);
	
	system("pause");
	return 0;
}