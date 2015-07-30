// 给定一组排好序的数，将该组数转化成范围字符串
//	注意整型转化为字符串，特别是负数

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string> ret;
		if(nums.empty())
			return ret;
		stringstream ss;
		string tt;
		if(nums.size() == 1) {
			int start = nums[0];
			ss << start;
			ss >> tt;
			ret.push_back(tt);
			return ret;
		}
        int start = nums[0];
		ss << start;
		ss >> tt;
		string str = tt;
		int end = start;
		for(int i=1; i<nums.size(); i++) {
			end++;
			if(end != nums[i]) {
				// 说明遇到了不递增的
				if(end == start+1)
					ret.push_back(str);
				else {
					str += "->";
					ss.clear();
					ss << nums[i-1];
					ss >> tt;
					str += tt;
					ret.push_back(str);
				}
				start = end = nums[i];
				str = "";
				ss.clear();
				ss << start;
				ss >> tt;
				str += tt;
				if(i == nums.size() - 1) {
					if(nums[i] != nums[i-1] + 1)
						ret.push_back(str);
				}
			}
			else if(i == nums.size() - 1) {
				str += "->";
				ss.clear();
				ss << nums[i];
				ss >> tt;
				str += tt;
				ret.push_back(str);
			}
		}
		return ret;
    }
};