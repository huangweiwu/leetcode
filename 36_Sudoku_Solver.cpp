//写程序解决一个数独题，空格用"."表示
//没想到什么好的解决方法，引入一个辅助函数，对每一个空格子，新加入一个数，并判断其是否满足当前所在行、列、小矩阵是否满足
//1） 满足则填充下一格格子
//2） 不满足则返回false，回溯
//填完最后一个也可以满足，返回true

class Solution {
public:
	bool isValidSudoku(vector<vector<char> > &board, int x, int y, int len) {
		//判断位置为(x, y)的格子是否满足
		int row, col;
		int sq = sqrt(len);
		for(row=0; row<9; row++) {
			//检查同一列
			if((x!=row) && (board[row][y]==board[x][y]))
				return false;
		}
		for(col=0; col<9; col++) {
			//检查同一行
			if((y!=col) && (board[x][col]==board[x][y]))
				return false;
		}
		for(row=(x/sq)*sq; row<(x/sq+1)*sq; row++) {
			//检查同一个方格
			for(col=(y/sq)*sq; col<(y/sq+1)*sq; col++) {
				if((x!=row) && (y!=col) && (board[row][col]==board[x][y]))
					return false;
			}
		}
		return true;
	}
	bool solveSudokuHelp(vector<vector<char> > &board) {
		int len = board.size();
		for(int i=0; i<len; i++) {
			for(int j=0; j<len; j++) {
				if(board[i][j] == '.') {
					for(int k=1; k<=9; k++) {
						//对当前空格子进行遍历
						board[i][j] = '0' + k;
						if(isValidSudoku(board, i, j, len)) {
							//如果当前填充的值满足，则对下一个格子进行处理
							if(solveSudokuHelp(board)) {
								return true;
							}
						}
						board[i][j] = '.';
					}
					//不满足则进行回溯
					return false;
				}
			}
		}
		return true;
	}
    void solveSudoku(vector<vector<char> > &board) {
        solveSudokuHelp(board);		//辅助函数，用于不满足时回溯
    }
};