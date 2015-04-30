//判断一个字符串是否有效数字
//思路：
//考虑很多的情况
//1） 首先去掉字符串开头的空格
//2） 直到遇到e之前必须是一个有效的数字
//3） 遇到e之后，必须是一个有效的整数

class Solution {
public:
    bool isNumber(const char *s) {
        if(s == NULL)
			return false;
		while(isspace(*s))
			s++;
		if(*s=='+' || *s=='-')
			s++;
		bool hasE = false;
		bool hasDot = false;
		bool hasSpace = false;
		bool firstpart = false;
		bool secondpart = false;
		while(*s != '\0') {
			if(*s == '.') {
				if(hasDot || hasE || hasSpace)
					return false;
				else
					hasDot = true;
			}
			else if(*s == 'e' || *s == 'E') {
				if(!firstpart || hasE || hasSpace)
					return false;
				else
					hasE = true;
			}
			else if(isdigit(*s)) {
				if(hasSpace)
					return false;

				if(!hasE)
					firstpart = true;
				else
					secondpart = true;
			}
			else if(*s=='+' || *s=='-') {
				if(hasSpace || !hasE || (*(s-1)!='e' && *(s-1)!='E'))
					return false;
			}
			else if(isspace(*s))
				hasSpace = true;
			else
				return false;
			s++;
		}
		if(!firstpart)
			return false;
		else if(hasE && !secondpart)
			return false;
		else
			return true;
    }
};