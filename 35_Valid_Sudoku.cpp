//判断一个给定的矩阵是否满足数独条件，该矩阵可能是非满矩阵，非满矩阵只需要判断有数字的方格是否满足即可，空的格子用"."表示
//思路：
//对每一行、每一列、每一个小方格里面的数判断是否满足条件
//用一个数组A[]来对每个数字出现的次数进行统计，则不满足条件存在两种情况
//1） 某一个方格数值大于len（方阵的维度）
//2） 某一个数的计数大于1

class Solution {
public:
    bool isValidSudoku(vector<vector<char> > &board) {
		int len = board.size();
		int *a = new int[len];
		memset(a, 0, len*sizeof(int));
		for(int i=0; i<len; i++) {
			//对每一行进行检查
			for(int j=0; j<len; j++) {
				if(board[i][j]-48 > len)
					return false;
				if(board[i][j] == '.')
					continue;
				else {
					if(++a[board[i][j]-'1'] > 1)
						return false;
				}
			}
			memset(a, 0, len*sizeof(int));
		}
		for(int j=0; j<len; j++) {
			//对每一列进行判断
			for(int i=0; i<len; i++) {
				if(board[i][j] == '.')
					continue;
				else {
					if(++a[board[i][j]-'1'] > 1)
						return false;
				}
			}
			memset(a, 0, len*sizeof(int));
		}
		int sq = sqrt(len);
		for(int i=0; i<sq; i++) {
			for(int j=0; j<sq; j++) {
				for(int p=i*sq; p<i*sq+sq; p++) {
					for(int q=j*sq; q<j*sq+sq; q++) {
						if(board[p][q] == '.')
							continue;
						else {
							if(++a[board[p][q]-'1'] > 1)
								return false;
						}
					}
				}
				memset(a, 0, len*sizeof(int));
			}
		}
		return true;
    }
};