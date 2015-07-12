#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include <stdint.h>
using namespace std;

// 给定一个数组，要将其后k位循环移至数组的首部
// 思路：将指定长度k分成的两部分，进行数组内的倒置；然后再进行整个数组的倒置
// 注意：需要先将k对数组的长度取余


class Solution {
public:
    void rotate(vector<int>& nums, int k) {
		int len = nums.size();
		k = k % len;
		if(len==0 || len==1 || k == 0)
			return;
		rotatehelp(nums, 0, len-k-1);
		rotatehelp(nums, len-k, len-1);
		rotatehelp(nums, 0, len-1);
    }
	void rotatehelp(vector<int>& nums, int start, int end) {
		int len = start + end;
		for(int i=start; i<=(end+start)/2; i++)
			swap(nums[i], nums[len - i]);
	}
};


int main() {
	Solution so;
	int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
	vector<int> v(arr, arr+8);
	so.rotate(v, 3);
	for(int i=0; i<8; i++)
		cout << v[i];

	system("pause");
	return 0;
}