//反过来将一个罗马数字转化为整型数，范围为1~3999
//思路：
//定义一个map数组，逐位与下一位的字母所代表的数值进行比较
//如果该位所代表的数值比下一位大，则加上该位所表示的数值
//如果该位所代表的数值比下一位小，则减去该位所表示的数值

class Solution {
public:
    int romanToInt(string s) {
        map<char, int> m;
		m['I'] = 1;  
        m['V'] = 5;  
        m['X'] = 10;  
        m['L'] = 50;  
        m['C'] = 100;  
        m['D'] = 500;  
        m['M'] = 1000;
		int i=0;
		int length = s.length();
		int result = 0;
		while(i < length-1) {
			if(m[s[i]] >= m[s[i+1]]) 
				result += m[s[i++]];
			else
				result -= m[s[i++]];
		}
		//加上最后一位
		result += m[s[i]];
		return result;
    }
};