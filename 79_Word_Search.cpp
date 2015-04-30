//给定一个二维board和一个单词，在二维board上查找该单词
//该单词在二维board上是由相邻的字符组成的，在这里的相邻指水平和竖直两个维度
//思路：回溯算法
//从第一个字符开始遍历，目标单词的第一个字符，则进行深度遍历，如果能找到目标单词，则返回true；若遍历完了还没找到则返回false


class Solution {
public:
	int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};		//四个方向
	bool exist_help(int i, int j, bool **flag, vector<vector<char> > &board, string word, int count) {
		if(board[i-1][j-1] == word[count]) {
			count++;
			if(count == word.length())
				return true;
			flag[i][j] = true;
			for(int k=0; k<4; k++) {
				if(flag[i+dir[k][0]][j+dir[k][1]] == true)
					continue;
				i += dir[k][0];
				j += dir[k][1];
				if(exist_help(i, j, flag, board, word, count))
					//如果找到了则返回true
					return true;
				i -= dir[k][0];
				j -= dir[k][1];
			}
			//四个方向都没找到，则返回false
			flag[i][j] = false;
			return false;
		}
		else
			return false;
	}
    bool exist(vector<vector<char> > &board, string word) {
		if(word.empty())
			return true;
		if(board.empty())
			return false;
        int row = board.size();
		int col = board[0].size();
		bool **flag = new bool*[row+2];
		for(int i=0; i<row+2; i++)
			flag[i] = new bool[col+2];
		for(int i=0; i<row+2; i++)//给定一个二维board和一个单词，在二维board上查找该单词
//该单词在二维board上是由相邻的字符组成的，在这里的相邻指水平和竖直两个维度
//思路：回溯算法
//从第一个字符开始遍历，目标单词的第一个字符，则进行深度遍历，如果能找到目标单词，则返回true；若遍历完了还没找到则返回false


class Solution {
public:
	int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};		//四个方向
	bool exist_help(int i, int j, bool **flag, vector<vector<char> > &board, string word, int count) {
		if(board[i-1][j-1] == word[count]) {
			count++;
			if(count == word.length())
				return true;
			flag[i][j] = true;
			for(int k=0; k<4; k++) {
				if(flag[i+dir[k][0]][j+dir[k][1]] == true)
					continue;
				i += dir[k][0];
				j += dir[k][1];
				if(exist_help(i, j, flag, board, word, count))
					//如果找到了则返回true
					return true;
				i -= dir[k][0];
				j -= dir[k][1];
			}
			//四个方向都没找到，则返回false
			flag[i][j] = false;
			return false;
		}
		else
			return false;
	}
    bool exist(vector<vector<char> > &board, string word) {
		if(word.empty())
			return true;
		if(board.empty())
			return false;
        int row = board.size();
		int col = board[0].size();
		bool **flag = new bool*[row+2];
		for(int i=0; i<row+2; i++)
			flag[i] = new bool[col+2];
		for(int i=0; i<row+2; i++)
			for(int j=0; j<col+2; j++)
				flag[i][j] = false;
		for(int i=0; i<row+2; i++) {
			//第一列，即board的外围为true，表示已经访问过
			flag[i][0] = true;
			flag[i][col+1] = true;
		}
		for(int j=0; j<col+2; j++) {
			//第一行也为true
			flag[0][j] = true;
			flag[row+1][j] = true;
		}
		
		for(int i=1; i<row+1; i++) {
			for(int j=1; j<col+1; j++) {
				int count = 0;
				if(exist_help(i, j, flag, board, word, count))
					return true;
			}
		}
		return false;
    }
};
			for(int j=0; j<col+2; j++)
				flag[i][j] = false;
		for(int i=0; i<row+2; i++) {
			//第一列，即board的外围为true，表示已经访问过
			flag[i][0] = true;
			flag[i][col+1] = true;
		}
		for(int j=0; j<col+2; j++) {
			//第一行也为true
			flag[0][j] = true;
			flag[row+1][j] = true;
		}
		
		for(int i=1; i<row+1; i++) {
			for(int j=1; j<col+1; j++) {
				int count = 0;
				if(exist_help(i, j, flag, board, word, count))
					return true;
			}
		}
		return false;
    }
};