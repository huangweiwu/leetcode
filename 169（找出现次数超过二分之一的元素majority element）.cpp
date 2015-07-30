// 给定一组数，返回majority element，即出现次数大于n/2次；可以假定数组非空，同时该数必然存在
//	思路：
//		位操作，用一个32位的mask，轮流在每位上置1，统计每个位置上出现的次数，如果出现的次数大于n/2，说明majority element在该位上为1


class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int major = 0;
		int bitCount;
		int len = nums.size();
		for(int i=0, mask=1; i<32; i++, mask <<= 1) {
			bitCount = 0;
			for(int j=0; j<len; j++) {
				if(nums[j] & mask)
					bitCount++;
				if(bitCount > len / 2) {
					major |= mask;
					break;
				}
			}
		}
		return major;
    }
};
