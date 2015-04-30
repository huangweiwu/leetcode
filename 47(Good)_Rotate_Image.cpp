//给定一个矩阵，将其顺时针翻转90度，空间复杂度O(1)
//先将矩阵沿对角线翻转，再沿水平线翻转

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {
        //沿对角线翻转
		int n = matrix.size();
		for(int i=0; i<n-1; i++) {
			//对每行，只需要操作对角线前的元素
			for(int j=0; j<n-1-i; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-1-j][n-1-i];
                matrix[n-1-j][n-1-i] = tmp;
			}
		}
		//沿水平线翻转
		for(int i=0; i<n/2; i++) {
			for(int j=0; j<n; j++) {
				int tmp = matrix[i][j];
				matrix[i][j] = matrix[n-i-1][j];
				matrix[n-i-1][j] = tmp;
			}
		}
    }
};