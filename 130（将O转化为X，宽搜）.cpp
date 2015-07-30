

// 给定一个二维矩阵，由'X'和'O'组成，如果有一片渔区的'0'被'X'包围，则将其全部转化为'X'
//	思路：
//		考虑最外围的元素，如果为'O'，则周围的点最后也必然为'O'，由最外围往里扩散

class Solution {
public:
    void solve(vector<vector<char>>& board) {
		if(board.size() <= 2)
			return;
		if(board[0].size() <= 2)
			return;
		int row = board.size();
		int col = board[0].size();
		for(int i=0; i<row; i++) {
			check(board, i, 0, row, col);		// 先检查第一列
			check(board, i, col-1, row, col);	// 再检查最后一列
		}
		for(int j=1; j+1<col; j++) {
			check(board, 0, j, row, col);		// 检查第一行
			check(board, row-1, j, row, col);	// 检查最后一行
		}
		for(int i=0; i<row; i++)
			for(int j=0; j<col; j++)
				board[i][j] = (board[i][j] == '1') ? 'O' : 'X';
    }
	void check(vector<vector<char>>& vec, int i, int j, int row, int col) {
		if(vec[i][j] == 'O') {
			// 如果是'O'，则需要改变其周围的元素，从最外围的开始扩散
			vec[i][j] = '1';
			if(i > 1)
				check(vec, i-1, j, row, col);
			if(j > 1)
				check(vec, i, j-1, row, col);
			if(i < row-1)
				check(vec, i+1, j, row, col);
			if(j < col-1)
				check(vec, i, j+1, row, col);
		}
	}
};
