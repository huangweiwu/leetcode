//查找一个整型数组中两个和为target的数的下标
//需注意的是，直接使用algorithm包中的find方法来做会超时
//本题先对数组进行排序，然后找出在排序数组中的两个值，再根据这两个值去原数中查找位置
//要注意两个数相等或者排序后两个数位置变化了的情况，容易出错

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result;
		vector<int> copy(numbers);
		sort(copy.begin(), copy.end());
		int i,j;
		bool flag = false;
		for(i=0; i<copy.size(); i++) {
			for(j=copy.size()-1; j>i; j--) {
				if(copy[i]+copy[j] == target) {
					flag = true;
					break;
				}
				else {
					if(copy[i]+copy[j] < target)
						break;
				}
			}
			if(flag)
				break;
		}
		int k=0;
		bool is_find_i = false;
		bool is_find_j = false;
		while(!(is_find_i && is_find_j)) {
			if(!is_find_i) {
				if(numbers[k] == copy[i]) {
					is_find_i = true;
					result.push_back(++k);
				}
			}
			if(!is_find_j) {
				if(numbers[k] == copy[j]) {
					is_find_j = true;
					result.push_back(k+1);
				}
			}
			k++;
		}
		return result;
    }
};