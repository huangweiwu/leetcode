//n-Queens：给定一个数字n，返回所有不出冲突的组合
//冲突的情况
//1） 在同一行/列
//2） 在同一条对角线
//思路：回溯法
//从每一行的第一个位置开始放置皇后，不与前面所有行冲突即可放置
//1） 没出现冲突则放置，并进行下一行
//2） 出现冲突则往后移一格，到达最后一个位置都有冲突则回溯
//注意结束条件：回溯到第一行，且第一行也已经到达了最后一列，则返回结果

class Solution {
public:
	bool isconq(vector<int> pos, int row, int col) {
		//判断在row行col列放置皇后是否会引起冲突
		for(int i=0; i<row; i++) {
			if(col==pos[i] || abs(col-pos[i])==abs(i-row))
				//在同一列或者对角线上
				return true;
		}
		return false;
	}
	void work(int n, vector<vector<string> > &result, vector<string> &solution) {
		int row = 0;
		int col = 0;
		vector<int> pos(n, 0);			//保存每一行中皇后的位置
		while(row<n && col<n) {
			if(!isconq(pos, row, col)) {
				//如果不冲突
				pos[row] = col;
				solution[row][col] = 'Q';
				if(row == n-1) {
					//如果到达最后一行，则将结果保存起来，并进行回溯
					result.push_back(solution);
					solution[row][col] = '.';
					row--;
					solution[row][pos[row]] = '.';
					while(pos[row] == n-1) {
						//如果回溯到的上一行，列位置刚好是最后一列，则继续回溯
						row--;
						solution[row][pos[row]] = '.';
					}
					col = pos[row] + 1;
				}
				else {
					//如果还没到达最后一行，则将该位置置为'Q'，并进入下一行
					row++;
					col = 0;
				}
				continue;
			}
			else {
				//如果冲突了
				if(col == n-1) {
					//如果到了最后一列，则进行回溯
					row--;
					solution[row][pos[row]] = '.';
					while(pos[row] == n-1) {
						//如果回溯到的上一行，列位置刚好是最后一列，则继续回溯
						if(row == 0)
							//回溯到了第一行，且第一行也遍历到了最后一个位置，则返回结果
							return;
						row--;
						solution[row][pos[row]] = '.';
					}
					col = pos[row] + 1;
				}
				else {
					//还没到最后一列
					col++;
				}
				continue;
			}
		}
	}
    vector<vector<string> > solveNQueens(int n) {
        vector<vector<string> > result;
		vector<string> solution;
		string init = "";
		for(int i=0; i<n; i++)
			init += '.';
		for(int i=0; i<n; i++)
			solution.push_back(init);

		if(n == 1) {
			solution[0][0] = 'Q';
			result.push_back(solution);
			return result;
		}

		if(n==2 || n==3) {
			result.clear();
			return result;
		}

		work(n, result, solution);

		return result;
    }
};