//给定一个m*n的方格阵，每个方格有一个非负整数
//从左上角往右下角走，每次只能向下或向右，求最小的路径数字和
//思路：动态规划
//f[m][n] = min(f[m-1][n], f[m][n-1]) + grid[m][n]

class Solution {
public:
    int minPathSum(vector<vector<int> > &grid) {
		int m = grid.size();
		int n = grid[0].size();
		int **f = new int*[m];
		for(int i=0; i<m; i++)
			f[i] = new int[n];
		f[0][0] = grid[0][0];
		
		for(int i=1; i<m; i++)
			//第一列为该格之上所有方格之和
				f[i][0] = f[i-1][0] + grid[i][0];
		for(int j=1; j<n; j++)
			//第一行为该格之左所有方格之和
				f[0][j] = f[0][j-1] + grid[0][j];
		if(m==1 || n==1)
			return f[m-1][n-1];
		for(int i=1; i<m; i++)
			for(int j=1; j<n; j++)
				f[i][j] = min(f[i-1][j], f[i][j-1]) + grid[i][j];
		return f[m-1][n-1];
    }
};