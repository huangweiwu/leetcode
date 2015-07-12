#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 给定一个只包含0和1的二维数组，求其中全部为1的最大的正方形面积
//	思路：动态规划
//		dp[i][j]表示以(i, j)点为正方形的右下角的点的最大面积
//		则	matrix[i][j] = 0时，dp[i][j] = 0
//			matrix[i][j] = 1时
//				matrix[i-1][j] == 0 或 matrix[i][j-1] == 0 或matrix[i-1][j-1]，dp[i][j] = 1
//				matrix[i-1][j]!=0 且matrix[i][j-1]且matrix[i-1][j-1]!=0，dp[i][j] = (sqrt(min(dp[i-1][j], dp[i][j-1], dp[i-1][j-1]))+1) ^ 2


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if(matrix.empty())
			return 0; 
		int row = matrix.size();
		int col = matrix[0].size();
		int** dp = new int*[row];
		int ret = 0;
		for(int i=0; i<row; i++)
			dp[i] = new int[col];
		for(int i=0; i<col; i++) {
			// 第一行的dp等于其本身的值
			dp[0][i] = matrix[0][i] - '0';
			if(dp[0][i] == 1)
				ret = 1;
		}
		for(int i=0; i<row; i++) {
			// 第一列的dp等于其本身的值
			dp[i][0] = matrix[i][0] - '0';
			if(dp[i][0] == 1)
				ret = 1;
		}
		
		for(int i=1; i<row; i++) {
			for(int j=1; j<col; j++) {
				if(matrix[i][j] == '0')
					dp[i][j] = 0;
				else {
					if(matrix[i-1][j] == '0' || matrix[i][j-1] == '0' || matrix[i-1][j-1] == '0')
						dp[i][j] = 1;
					else {
						int tmp = sqrt(minofthree(dp[i-1][j], dp[i][j-1], dp[i-1][j-1])) + 1;
						dp[i][j] = tmp * tmp;
					}
					if(dp[i][j] > ret)
						ret = dp[i][j];
				} 
			}
		}
		return ret;
    }

	int minofthree(int a1, int a2, int a3) {
		int tmp = min(a1, a2);
		return min(tmp, a3);
	}
};

int main() {
	Solution so;
	vector<vector<char>> matrix;
	char a1[] = {'1', '1', '1', '1'};
	char a2[] = {'1', '1', '1', '1'};
	char a3[] = {'1', '1', '1', '1'};
	//char a4[] = {'1', '0', '0', '1', '0'};
	vector<char> v1(a1, a1+4);
	vector<char> v2(a2, a2+4);
	vector<char> v3(a3, a3+4);
	//vector<char> v4(a4, a4+5);
	matrix.push_back(v1);
	matrix.push_back(v2);
	matrix.push_back(v3);
	//matrix.push_back(v4);

	cout << so.maximalSquare(matrix)  << endl;

	system("pause");
	return 0;
}