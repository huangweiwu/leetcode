// 给定一组数，判断其中是否存在i,j使得nums[i] - nums[j] <= t，且abs(i-j) <= k
//	思路：
//		用set存储，set是一个排序的集合（红黑二叉树），每次用lower_bound查找大于等于nums[i] - t的第一个元素位置
//		如果找到的元素不在set的末端，且该位置的值小于等于nums[i] + t，则返回true

//		小技巧：set里只保存从nums[i-k]开始的元素

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        set<long> s;
		for(int i=0; i<nums.size(); i++) {
			if(i > k)
				s.erase(nums[i - k - 1]);
			auto pos = s.lower_bound((long)nums[i] - (long)t);
			if(pos != s.end() && *pos <= ((long)nums[i] + (long)t))
				return true;
			s.insert(nums[i]);
		}
		return false;
    }
};