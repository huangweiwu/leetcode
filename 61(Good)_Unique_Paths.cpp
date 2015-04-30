//给定一个m*n的矩形方阵
//有一个机器人，从左上角出发，目的地为右下角，机器人每次只能向下或者向右
//求所有可能的路径总数
//思路：深度优先搜索对于每一个位置，如果可以向右走则向右走，如果不能向右走则向下走
//走到目标位置，则result++；并进行回溯
//超时

class Solution {
public:
    	int uniquePaths(int m, int n) {
		if(m==1 || n==1)
			return 1;
		int result = 0;
        bool ***flag = new bool **[m+1];
		for(int i=0; i<m+1; i++)
			flag[i] = new bool*[n+1];
		for(int i=0; i<m+1; i++)
			for(int j=0; j<n+1; j++)
				flag[i][j] = new bool[2];
		for(int i=0; i<m+1; i++)
			for(int j=0; j<n+1; j++)
				for(int k=0; k<2; k++)
					flag[i][j][k] = true;
		//表示所有的方格向右和向下都没走过
		for(int i=1; i<=m; i++)
			flag[i][n][0] = false;		//最后一列无法向右
		for(int i=1; i<=n; i++)
			flag[m][i][1] = false;		//最后一行无法向下
		int x = 1, y = 1;
		int *pre = new int[201];		//表示之前走过的路径，0表示向右，1表示向下
		for(int i=0; i<201; i++)
			pre[i] = 0;
		int pre_len = 0;				//表示之前走过的路径长度
		while(!(x==m && y==1)) {
		//直到回溯到x到达最后一行，而y还在第一列，则剩下最后一跳路径，跳出循环
			if(flag[x][y][0]) {
			//如果可以向右
				flag[x][y][0] = false;
				y++;
				pre_len++;
				pre[pre_len] = 0;
			}
			else if(flag[x][y][1]) {
			//如果只能向下
				flag[x][y][1] = false;
				x++;
				pre_len++;
				pre[pre_len] = 1;
			}
			else {
			//进行回溯
				while(!flag[x][y][0] && !flag[x][y][1]) {
					if(y != n)
					//回溯的时候要注意，最后一列依然不能向右
						flag[x][y][0] = true;
					if(x != m)
						flag[x][y][1] = true;
					if(pre[pre_len] == 0) 
						y--;
					else
						x--;
					pre_len--;
				}
			}
			if(x==m && y==n)
				result++;
		}
		result++;
		return result;
    	}
};

//由于只能往下或者往右走，因此(i, j)只会由(i - 1, j)或者(i, j - 1)到达。
//假设，到达(i - 1, j)有f[i - 1, j]种走法，到达(i, j - 1)有f[i, j - 1]种走法，那么到达(i, j)有f[i, j] = f[i - 1, j] + f[i, j - 1]中走法

class Solution {
public:
    	int uniquePaths(int m, int n) {
		if(m==1 || n==1)
			return 1;
		int **result = new int*[m];
		for(int i=0; i<m; i++)
			result[i] = new int[n];
		for(int j=0; j<n; j++)
			result[0][j] = 1;
		for(int i=0; i<m; i++)
			result[i][0] = 1;
		for(int i=1; i<m; i++)
			for(int j=1; j<n; j++)
				result[i][j] = result[i-1][j] + result[i][j-1];

		return result[m-1][n-1];
		}
};