// 给定一组数，返回是否包含两个以上同样的数

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, bool> m;
		for(int i=0; i<nums.size(); i++) {
			if(m[nums[i]])
				return true;
			else
				m[nums[i]] = true;
		}
		return false;
    }
};