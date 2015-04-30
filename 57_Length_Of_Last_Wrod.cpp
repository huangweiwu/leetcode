//给定一组以" "隔开的字符串，返回最后一个字符串的长度，如果没有的话则返回0
//思路：
//利用strtok函数

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int result = 0;
		if(strlen(s) == 0)
			return result;
		char *pNext = NULL;
		char *temp = strtok_s((char *)s, " ", &pNext);
		while(temp != NULL) {
			result = strlen(temp);
			temp = strtok_s(NULL, " ", &pNext);
		}
		return result;
    }
};