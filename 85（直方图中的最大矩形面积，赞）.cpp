#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include <stdint.h>
using namespace std;

// 最大直方图面积
// 思路：维持一个栈，栈里保存高度单调递增的各个直方的下标
//  遍历所有的直方i
//	若栈为空，则索引i入栈
//	若栈不为空
//		若height[i] < height[stack.top]，则往左求栈里索引元素组成的最大面积，同时将最大面积的直方所对应的下标出栈
//			最大面积的计算：（height[t] * (stack.empty() ? i : i - stack.top() - 1)），height[t]为最后一个弹出的元素【最后一个不比hegith[i]小的元素】
//		若height[i] >= height[stack.top]，将当前元素下标入栈

// 注意考虑到最后一列，需要我们手动添加一列高度为0的方图

class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
		if(height.size() == 0)
			return 0;
		if(height.size() == 1)
			return height[0];
		height.push_back(0);
		int ret = 0;
		stack<int> s;
		for(int i=0; i<height.size(); i++) {
			if(s.empty() || (!s.empty() && height[i] >= height[s.top()]))
				s.push(i);
			else {
				while(!s.empty() && height[s.top()] > height[i]) {
					int t = s.top();
					s.pop();
					ret = max(ret, height[t] * (s.empty() ? i : i - s.top() - 1));
				}
				s.push(i);
			}
		}

		return ret;
    }
};


int main() {
	Solution so;
	int a[6] = {2, 1, 5, 6, 2, 3};
	vector<int> v(a, a+6);
	cout << so.largestRectangleArea(v) << endl;

	system("pause");
	return 0;
}