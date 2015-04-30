//实现strstr()，返回字符串haystack中子串needle的位置
//思路
//获得needle的长度len
//1） 如果长度为零，直接返回haystack
//2） 如果长度不为零，遍历haystack，比较两个字符串长度为len的子串，若找到相等的则返回该位置
//strncmp与strcmp的区别是前者能指定比较的长度
//加速：当haystack剩下的长度小于len，则直接返回NULL

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        int len = strlen(needle);
		if(!len)
			return haystack;
		for(; *haystack; haystack++) {
			if(!strncmp((const char*) haystack, (const char*) needle, len))
				return haystack;
			if(strlen(haystack) < len)
				//如果剩下的长度小于len，则直接返回NULL
				break;
		}
		return NULL;
    }
};