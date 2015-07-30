// 给定一个未排序的数组，求按排好序的顺序的最大相邻间隔，要求时间和空间复杂度均为O(n)
//	思路：
//		借助桶排序的思想，最大最小值分别为maxvalue/minvalue，从而最大简直至少为gap = (maxvalue - minvalue - 1) / (n - 1) + 1
//		构造2n个桶，分别存放(minvalue, minvalue + gap), [minvalue + gap, minvalue + 2gap), ..., [minvalue + (n-2)gap, maxvalue)区间内的最大值最小值
//		遍历数组求得每个桶的最大最小值，最后遍历桶来求得最大间隔

class Solution {
public:
    int maximumGap(vector<int>& nums) {
		if(nums.size() < 2)
			return 0;
		int maxvalue = INT_MIN;
		int minvalue = INT_MAX;
		for(auto num : nums) {
			maxvalue = max(num, maxvalue);
			minvalue = min(num, minvalue);
		}
		int length = nums.size();
		int gap = (maxvalue - minvalue - 1) / (length - 1) + 1;
		vector<int> minv(length, INT_MAX);
		vector<int> maxv(length, INT_MIN);
		for(auto num : nums) {
			if(num == maxvalue || num == minvalue)
				continue;
			int pos = (num - minvalue) / gap;		// num落在哪个桶中
			minv[pos] = min(minv[pos], num);
			maxv[pos] = max(maxv[pos], num);
		}

		int ret = INT_MIN;
		int previous = minvalue;			// 前一个有值的桶的最大值
		for(int i=0; i<length; i++) {
			// 遍历所有的桶取得最大间隔
			if(minv[i] == INT_MAX && maxv[i] == INT_MIN)
				// 空桶
				continue;
			ret = max(ret, minv[i] - previous);
			previous = maxv[i];
		}
		ret = max(ret, maxvalue - previous);	// 最后一个区间
		return ret;
    }
};