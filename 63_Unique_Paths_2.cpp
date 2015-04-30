//跟在"Unique Paths"后面的题目，对于每个格子有两种状态，一种是空格子，一种是被占用的，即无法通过
//在这种情况下求路径数
//思路：
//第一行和第一列的初始值，只要其中出现一个1，则后面都为0
//其他的对上边一格和左边一格进行判断，若为0，则加上其值

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int> > &obstacleGrid) {
		if(obstacleGrid[0][0] == 1)
			return 0;
		int m = obstacleGrid.size();
		int n = obstacleGrid[0].size();

        if(m==1 || n==1) {
			if(obstacleGrid[m-1][n-1] == 1)
				return 0;
			return 1;
		}
		int **result = new int*[m];
		for(int i=0; i<m; i++)
			result[i] = new int[n];
		for(int i=0; i<m; i++)
			for(int j=0; j<n; j++)
				result[i][j] = 0;
		for(int i=0; i<m; i++) {
			if(obstacleGrid[i][0] == 1)
				break;
			result[i][0] = 1;
		}
		for(int j=0; j<n; j++) {
			if(obstacleGrid[0][j] == 1)
				break;
			result[0][j] = 1;
		}
		for(int i=1; i<m; i++) {
			for(int j=1; j<n; j++) {
				if(obstacleGrid[i][j] == 1)
					continue;
				if(obstacleGrid[i-1][j] == 0)
					result[i][j] += result[i-1][j];
				if(obstacleGrid[i][j-1] == 0)
					result[i][j] += result[i][j-1];
			}
		}
		return result[m-1][n-1];
    }
};