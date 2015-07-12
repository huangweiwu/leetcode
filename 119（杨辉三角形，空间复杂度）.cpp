#include<iostream>
#include<vector>
#include<set>
using namespace std;

// 求杨辉三角形第i行的数据，要求空间复杂度为O(i)
// 思路：用两个数组保存当前行和上一行的结果；odd保存奇数行结果，even保存偶数行结果

class Solution {
public:
    vector<int> getRow(int rowIndex) {
		vector<int> ret;
		if(rowIndex == 1) {
			ret.push_back(1);
			ret.push_back(1);
			return ret;
		}
		int* odd = new int[rowIndex + 1];
		int* even = new int[rowIndex + 1];
		for(int i=0; i<=rowIndex; i++) {
			odd[i] = 1;
			even[i] = 1;
		}
		for(int i=2; i<=rowIndex; i++) {
			if(i & 0x01) {
				for(int j=1; j<i; j++) {
					odd[j] = even[j-1] + even[j];
				}
			}
			else {
				for(int j=1; j<i; j++) {
					even[j] = odd[j-1] + odd[j];
				}
			}
		}
		if(rowIndex & 0x01) {
			for(int i=0; i<=rowIndex; i++)
				ret.push_back(odd[i]);
		}
		else {
			for(int i=0; i<=rowIndex; i++)
				ret.push_back(even[i]);
		}
		return ret;
    }
};

int main() {
	Solution so;
	vector<int> ret = so.getRow(4);

	system("pause");
	return 0;
}