// 给定一组数，返回另外一组数，其中output[i]为除了num[i]之外所有数的乘积
// 要求：不用除法，线性时间，用常数空间
//	思路：
//		先正序乘，对于output[i]，为从num[0] 乘到 num[i-1]
//		再逆序乘，对于output[i]，将其乘上num[n-1]到num[i+1]


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> output(nums.size());
		for(int i=0, prev=1; i<nums.size(); prev*=nums[i], i++)
			output[i] = prev;
		for(int i=nums.size()-1, prev=1; i>=0; prev*=nums[i], i--)
			output[i] *= prev;
		return output;
    }
};
