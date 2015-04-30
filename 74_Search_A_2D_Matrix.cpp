//有一个二维矩阵，每一行从左到右递增，后一行的第一个数比前一行的最后一个数大
//在该矩阵中查找某个数，找到则返回true，没找到则返回false
//思路：
//两次二分查找

class Solution {
public:
    bool searchMatrix(vector<vector<int> > &matrix, int target) {
		if(target < matrix[0][0] || target > matrix[matrix.size()-1][matrix[0].size()-1])
			return false;
		int begin = 0;
		int end = matrix.size() - 1;
		//先找到所在的行
		int row = 0;
		while(begin <= end) {
			int mid = (begin + end) / 2;
			if(target>=matrix[mid][0] && target<=matrix[mid][matrix[0].size()-1]) {
				row = mid;
				break;
			}
			else if(target<matrix[mid][0])
				end = mid - 1;
			else
				begin = mid + 1;
		}
		//再对所在的行进行二分查找
		begin = 0;
		end = matrix[0].size() - 1;
		while(begin <= end) {
			int mid = (begin + end) / 2;
			if(target == matrix[row][mid])
				return true;
			else if(target > matrix[row][mid])
				begin = mid + 1;
			else
				end = mid - 1;
		}
		return false;
    }
};