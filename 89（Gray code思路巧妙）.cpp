#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include <stdint.h>
using namespace std;

// 给一个数n，返回它的Gray code
//	Gray code表示长度为n的01二进制数，每次只能修改一位；且第一个数必须为0，每一个01串只能出现一次，将这个数序列返回
//	思路：动态添加位数，不考虑添加的位0/1，后半部分是对称的

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    vector<int> grayCode(int n) {
        if (!n) 
            return std::vector<int>(1);
        vector<int> res = grayCode(n - 1);
        int add_num = 1 << (n - 1);
        for (int i = res.size() - 1; i >= 0; --i)
            res.push_back(res[i] + add_num);
        return res;
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

	
	system("pause");
	return 0;
}