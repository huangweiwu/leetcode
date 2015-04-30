//求一个字符串数组的最长公共前缀
//没有什么好的方法
//思路
//1） 如果存在长度为0的字符串数组，则直接返回""
//2） 最长公共前缀的长度不会超过长度最短的字符串，从而一开始比较的长度不超过最短字符串的长度
//3） 每两个进行比较后需要更新这个最短长度

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
		string result = "";
		if(strs.size() == 0)
			//如果字符串数组长度为0
			return result;
		int max_len = strs[0].length();				//保存当前要比较的长度
		for(int i=0; i<strs.size(); i++) {
			if(strs[i].length() == 0)
				//如果存在长度为0的字符串
				return result;
			else {
				if(max_len > strs[i].length())
					max_len = strs[i].length();
			}
		}
		int temp_len = 0;
		for(int i=1; i<strs.size(); i++) {
			if(max_len == 0)
				//如果当前的最长长度为0，直接跳出循环
				break;
			temp_len = 0;
			for(int j=0; j<max_len; j++) {
				if(strs[0][j] != strs[i][j])
					break;
				else
					temp_len++;
			}
			max_len = min(temp_len, max_len);
		}
		result = strs[0].substr(0, max_len);
		return result;
    }
};