#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include<stack>
#include <stdint.h>
using namespace std;

// 利用求直方图最大面积的思想，对矩阵按每一行来遍历，遍历到第i行，求每一列的连续1的个数的高度，然后求以该行为底的最大矩形面积

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
		int row = matrix.size();
		if(row == 0)
			return 0;
		int col = matrix[0].size();
		if(col == 0)
			return 0;

		int* dpheight = new int[col];
		for(int i=0; i<col; i++) 
			dpheight[i] = 0;

		int ret = 0;
		for(int i=0; i<row; i++) {
			// 先动态更新每一列在以该行为底的高度
			for(int j=0; j<col; j++) {
				if(matrix[i][j] == '0')
					dpheight[j] = 0;
				else
					dpheight[j]++;
			}
			ret = max(ret, maxAreaOfHistol(dpheight, col));
		}
		return ret;
    }

	int maxAreaOfHistol(int* height, int col) {
		stack<int> s;
		s.push(0);
		int ret = 0;
		for(int i=0; i<col+1; i++) {
			if(s.empty() || (!s.empty() && height[i] > height[s.top()]))
				s.push(i);
			else {
				while(!s.empty() && height[s.top()] > height[i]) {
					int tmp = s.top();
					s.pop();
					ret = max(ret, height[tmp] * (s.empty() ? i : i - s.top() - 1));
				}
				s.push(i);
			}
		}
		return ret;
	}
};


int main() {
	Solution so;
	char ch1[2] = {'0', '1'};
	//char ch2[4] = {'1', '0', '1', '1'};
	//char ch3[4] = {'1', '0', '1', '1'};
	//char ch4[4] = {'1', '1', '1', '1'};
	vector<char> v1(ch1, ch1+2);
	//vector<char> v2(ch2, ch2+4);
	//vector<char> v3(ch3, ch3+4);
	//vector<char> v4(ch4, ch4+4);
	vector<vector<char> > matrix;

	matrix.push_back(v1);

	cout << so.maximalRectangle(matrix);

	system("pause");
	return 0;
}