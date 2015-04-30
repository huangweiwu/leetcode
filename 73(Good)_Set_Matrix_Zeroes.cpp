//给定一个m*n矩阵，如果某一个元素值为0，则将其同一行和同一列的元素置0
//主要难点在于空间复杂度
//思路：
//1） O(mn)，直接重新构造一个matrix
//2） O(m+n)，创建两个向量，用于保存哪些行列需要转换为0
//3） O(1)，直接利用原矩阵的第一行和第一列来保存哪些行列需要转换为0，但需要两个变量来表示最后第一行和第一列是否要转换为0

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        bool firstrow = false;
		bool firstcol = false;
		for(int i=0; i<matrix[0].size(); i++) {
			if(matrix[0][i] == 0) {
				firstrow = true;
				break;
			}
		}
		for(int j=0; j<matrix.size(); j++) {
			if(matrix[j][0] == 0) {
				firstcol = true;
				break;
			}
		}
		for(int i=1; i<matrix[0].size(); i++) {
			for(int j=1; j<matrix.size(); j++) {
				if(matrix[j][i] == 0) {
					matrix[0][i] = 0;
					matrix[j][0] = 0;
				}
			}
		}
		for(int i=1; i<matrix[0].size(); i++) {
			if(matrix[0][i] == 0) {
				for(int j=1; j<matrix.size(); j++) {
					matrix[j][i] = 0;
				}
			}
		}
		for(int j=1; j<matrix.size(); j++) {
			if(matrix[j][0] == 0) {
				for(int i=1; i<matrix[0].size(); i++) {
					matrix[j][i] = 0;
				}
			}
		}
		if(firstrow) {
			for(int i=0; i<matrix[0].size(); i++) {
				matrix[0][i] = 0;
			}
		}
		if(firstcol) {
			for(int j=0; j<matrix.size(); j++) {
				matrix[j][0] = 0;
			}
		}
    }
};