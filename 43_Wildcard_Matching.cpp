//实现支持"?"/"*"的通配符模式匹配
//"?"匹配任何单个字符
//"*"匹配任何字符序列
//思路：
//动态规划，判断当前字符是否"*"
//如果不是"*"，则当前字符必须匹配才能返回isMatch(s+1, p+1)，否则返回false
//如果是"*"，则对i进行循环，返回isMatch(s+i, p+1)
//发生错误：Time Limit Exceeded，确实对i进行循环判断那一步复杂度太高

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0')
			return *s == '\0';
		if(*s == '\0') {
			if(*p == '*')
				return isMatch(s, p+1);
			else
				return *p == '\0';
		}
		if(*p != '*') {
			//如果当前字符不为"*"
			if(*s==*p || (*p=='?' && *s!='\0'))
				//当前字符必须匹配或者*p为"?"且s没终止，则返回isMatch(s+1, p+1)
				return isMatch(s+1, p+1);
			else
				return false;
		}
		else {
			//如果当前字符为"*"，则p移动一位，对s进行移动0到len位的匹配，只要其中一个为真，则返回true；如果全部都不匹配，则返回false
			char *tmp = (char *)s;
			for(int i=0; *tmp!='\0'; i++) {
				if(isMatch(s+i, p+1))
					return true;
				tmp++;
			}
			return false;
		}
    }
};

//实现支持"?"/"*"的通配符模式匹配
//"?"匹配任何单个字符
//"*"匹配任何字符序列
//思路：
//动态规划，判断当前字符是否"*"
//如果不是"*"，则当前字符必须匹配才能返回isMatch(s+1, p+1)，否则返回false
//对上面一种方法进行改进，如果是连续两个"**"，则跳过当前的"*"继续进行下一个的判断
//结果还是不行
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        if(*p == '\0')
			return *s == '\0';
		if(*s == '\0') {
			if(*p == '*')
				return isMatch(s, p+1);
			else
				return *p == '\0';
		}
		if(*p != '*') {
			//如果当前字符不为"*"
			if(*s==*p || (*p=='?' && *s!='\0'))
				//当前字符必须匹配或者*p为"?"且s没终止，则返回isMatch(s+1, p+1)
				return isMatch(s+1, p+1);
			else
				return false;
		}
		else {
			if(*(p-1)=='*')
				//如果是连续两个"**"，则跳过当前的"*"继续进行下一个的判断
				return isMatch(s, p+1);
			char *tmp = (char *)s;
			for(int i=0; *tmp!='\0'; i++) {
				if(isMatch(s+i, p+1))
					return true;
				tmp++;
			}
			return false;
		}
    }
};

//实现支持"?"/"*"的通配符模式匹配
//"?"匹配任何单个字符
//"*"匹配任何字符序列
//思路：
//贪心算法
//如果当前匹配的，则s++, p++
//如果当前不匹配，则判断*p是否为"*"
//是的话记录当前p的位置star，以前当前s正在匹配的位置temp_s
//不是的话则看前面是否
//		有保存的p的位置，有的话则进行回溯，p=star+1, s=temp_s+1, temp_s++
//		没有的话则返回false

class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        const char *star = NULL;
		const char *temp_s = NULL;
		while(*s) {
			if(*s==*p || *p=='?') {
				s++;
				p++;
				continue;
			}
			if(*p == '*') {
				star = p;
				temp_s = s;
				p++;
				continue;
			}
			if(star != NULL) {
				p = star + 1;
				s = temp_s + 1;
				temp_s++;			//对p中出现"*"的地方，s可以跳过任意长度的字符
				continue;
			}
			return false;
		}
		while(*p == '*')
			//如果s到达了末尾，则必须跳过p中所有的'*'，看能否达到末尾，能的话则匹配成功
			p++;
		return *p=='\0';
    }
};