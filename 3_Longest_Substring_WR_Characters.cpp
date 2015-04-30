//寻找最长不包含重复字母的子串，并返回其长度
//本题使用了string的find()和substr()函数
//find()在字符串中查找某个字符，若找到则返回其位置，没找到则返回npos
//substr(start, length)获取某个字符串从start位置开始，长度为length的子串

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int i=0;				//表示当前遍历到的字符串的位置
		string temp_str = "";
		int result = 0;
		while(i < s.length()) {
			if(temp_str.find(s[i]) != temp_str.npos){
				//如果找到该字符，则截取字符串，并把当前的长度与最优解做比较
				result = temp_str.length()>result?temp_str.length():result;
				int pos = temp_str.find(s[i]);
				temp_str = temp_str.substr(pos+1, temp_str.length()-pos-1);
			}
			temp_str += s[i++];
		}
		result = temp_str.length()>result?temp_str.length():result;
		return result;
    }
};