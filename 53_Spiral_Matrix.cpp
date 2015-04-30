//给定一个矩阵，以螺旋顺序返回该矩阵
//思路：
//递归的遍历每一个环形，右/下/左/上四个方向进行遍历
//对于最外层的环形，每个方向走的步数,step = n-1;
//往内一层则步数减2
//当n减少为1或者2时则遍历完最后一层并返回

//当矩阵为方阵时比较简单
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int head[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int x = 0;
		int y = 0;
		
		int n =  matrix.size();
		if(n - 1 < 0) {
			//矩阵为空
			vector<int> result;
			result.clear();
			return result;
		}

		vector<int> result(n*n, 0);
		n -= 1;
		int i = 0;

		while(n >= 1) {
			for(int j=0; j<4; j++) {
				//从四个方向读矩阵的数
				for(int k=0; k<n; k++) {
					//每个方向读n个数
					result[i++] = matrix[x][y];
					x += head[j][0];
					y += head[j][1];
				}
			}
			n -= 2;
			x += 1;
			y += 1;
		}
		if(n == 0)
			result[i] = matrix[x][y];

		return result;
    }
};

//下面是针对m != n的情况
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
		int head[4][4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
		int x = 0;
		int y = 0;
		
		int row = matrix.size();		//行数
		if(row - 1 < 0) {
			//矩阵为空
			vector<int> result;
			result.clear();
			return result;
		}
		int col = matrix[0].size();		//列数

		vector<int> result(row*col, 0);
		row -= 1;
		col -= 1;
		int i = 0;

		while((row >= 1 && col >= 0) || (row >= 0 && col >= 1)) {
			for(int j=0; j<4; j++) {
				//从四个方向读矩阵的数
				if(j & 1) {
					//从竖直方向读
					for(int k=0; k<row; k++) {
						result[i++] = matrix[x][y];
						x += head[j][0];
						y += head[j][1];
					}
					if(col == 0) {
						//最后剩下单行，则读完该完后跳出循环
						result[i++] = matrix[x][y];
						break;
					}
				}
				else {
					//从水平方向读
					for(int k=0; k<col; k++) {
						result[i++] = matrix[x][y];
						x += head[j][0];
						y += head[j][1];
					}
					if(row == 0) {
						//最后剩下单列，则读完该列后跳出循环
						result[i++] = matrix[x][y];
						break;
					}
				}
			}
			row -= 2;
			col -= 2;
			x += 1;
			y += 1;
		}
		if(row==0 && col==0)
			result[i] = matrix[x][y];

		return result;
    }
};