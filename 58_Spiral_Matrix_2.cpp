//给定数字n，产生螺旋方阵
class Solution {
public:
    vector<vector<int> > generateMatrix(int n) {
		vector<vector<int> > result(n);
		if(n - 1 < 0) {
			//矩阵为空
			result.clear();
			return result;
		}
		vector<int> tmp(n);
		for(int t=0; t<n; t++)
			result[t] = tmp;
		int head[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int x = 0;
		int y = 0;
		if(n & 1)
			result[n/2][n/2] = n*n;
		n -= 1;
		int i = 1;

		while(n >= 1) {
			for(int j=0; j<4; j++) {
				//从四个方向读矩阵的数
				for(int k=0; k<n; k++) {
					//每个方向读n个数
					result[x][y] = i;
					i++;
					x += head[j][0];
					y += head[j][1];
				}
			}
			n -= 2;
			x += 1;
			y += 1;
		}

		return result;
    }
};