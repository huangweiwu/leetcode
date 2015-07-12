#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include <stdint.h>
using namespace std;

// 合并有序数组
// 思路：维护两个指针即可


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		if(m == 0) {
			int t = 0;
			nums1.clear();
			while(t < n) {
				nums1.insert(nums1.begin()+m, nums2[t++]);
				m++;
			}
			return;
		}
		if(n == 0)
			return;
		int i = 0;
		int j = 0;
		for(; i<n; i++) {
			while(j < m && nums2[i] > nums1[j])
				j++;
			if(j == m)
				break;
			nums1.insert(nums1.begin() + j, nums2[i]);
			m++;
		}
		while(i<n) {
			nums1.insert(nums1.begin()+m, nums2[i++]);
			m++;
		}
		while(nums1.size() > m)
			nums1.erase(nums1.end()-1);
    }
};


int main() {
	Solution so;
	int nums1[1] = {0};
	int nums2[1] = {1};
	vector<int> v1(nums1, nums1+1);
	vector<int> v2(nums2, nums2+1);
	
	so.merge(v1, 0, v2, 1);

	for(int i=0; i<2; i++)
		cout << v1[i] << endl;

	system("pause");
	return 0;
}