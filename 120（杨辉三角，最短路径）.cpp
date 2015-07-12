#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include <stdint.h>
using namespace std;

// 求一个杨辉三角形，从上到下最短的路径
// 动态规划
// 对于第i行，第一个元素和最后一个元素的最短路径只能是一直往左或一直往右，dpcur[0] = dppre[0] + a[0]，dpcur[i-1] = dppre[i-2] + a[i-1]
//	其他元素，则两种选择，dpcur[i] = min{dppre[i-1], dppre[i]} + a[i]
//	算法复杂度：所有元素遍历一遍


class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
		if(triangle.size() == 0)
			return 0;
		if(triangle.size() == 1)
			return triangle[0][0];
		int row = triangle.size();
		int* dpodd = new int[row];
		int* dpeven = new int[row];
		dpodd[0] = triangle[0][0];
		int ret = 1000000;
		int i = 2;
		for(; i<row; i++) {
			if(i & 0x01) {
				dpodd[0] = dpeven[0] + triangle[i-1][0];
				dpodd[i-1] = dpeven[i-2] + triangle[i-1][i-1];
				for(int j=1; j<i-1; j++) {
					dpodd[j] = min(dpeven[j-1], dpeven[j]) + triangle[i-1][j];
				}
			}
			else {
				dpeven[0] = dpodd[0] + triangle[i-1][0];
				dpeven[i-1] = dpodd[i-2] + triangle[i-1][i-1];
				for(int j=1; j<i-1; j++) {
					dpeven[j] = min(dpodd[j-1], dpodd[j]) + triangle[i-1][j];
				}
			}
		}
		if(i & 0x01) {
			dpodd[0] = dpeven[0] + triangle[i-1][0];
			if(dpodd[0] < ret)
				ret = dpodd[0];
			dpodd[i-1] = dpeven[i-2] + triangle[i-1][i-1];
			if(dpodd[i-1] < ret)
				ret = dpodd[i-1];
			for(int j=1; j<i-1; j++) {
				dpodd[j] = min(dpeven[j-1], dpeven[j]) + triangle[i-1][j];
				if(dpodd[j] < ret)
					ret = dpodd[j];
			}
		}
		else {
			dpeven[0] = dpodd[0] + triangle[i-1][0];
			if(dpeven[0] < ret)
				ret = dpeven[0];
			dpeven[i-1] = dpodd[i-2] + triangle[i-1][i-1];
			if(dpeven[i-1] < ret)
				ret = dpeven[i-1];
			for(int j=1; j<i-1; j++) {
				dpeven[j] = min(dpodd[j-1], dpodd[j]) + triangle[i-1][j];
				if(dpeven[j] < ret)
					ret = dpeven[j];
			}
		}
		return ret;
    }
};


int main() {
	Solution so;
	int a1[1] = {2};
	int a2[2] = {3, 4};
	int a3[3] = {6, 5, 7};
	int a4[4] = {4, 1, 8, 3};

	vector<int> v1(a1, a1+1);
	vector<int> v2(a2, a2+2);
	vector<int> v3(a3, a3+3);
	vector<int> v4(a4, a4+4);

	vector<vector<int> > triangle;
	triangle.push_back(v1);
	triangle.push_back(v2);
	//triangle.push_back(v3);
	//triangle.push_back(v4);
	cout << so.minimumTotal(triangle) << endl;

	system("pause");
	return 0;
}