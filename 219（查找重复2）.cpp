// 给定一组数和一个数k，找到其中是否存在nums[i] == nums[j]，且i与j距离最多为k
//	思路：用一个unordered_map存储<nums[i], i>
//		遍历到i的时候，如果能找到一个t = m[nums[i]]，abs(i-t) <= k，则返回true 

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int> m;
		for(int i=0; i<nums.size(); i++) {
			if(m.find(nums[i]) == m.end()) {
				m[nums[i]] = i;
				continue;
			}
			if(i - m[nums[i]] <= k)
				return true;
			m[nums[i]] = i;
		}
		return false;
    }
};