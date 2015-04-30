//将一个字符串按照之字形排列，然后输出排列后再按行接起来的串
//要注意的地方
//1） 字符串不能动态创建数组
//2） 长度为1和2的情况

#include<iostream>
#include<string>
using namespace std;

typedef struct str {
	string s;
}str_array;

class Solution {
public:
    string convert(string s, int nRows) {
		if(nRows == 1)
			return s;
		if(nRows == 2) {
			string str1="", str2="";
			for(int i=0; i<s.length(); i++) {
				if(i%2 == 0)
					str1 += s[i];
				else
					str2 += s[i];
			}
			str1 += str2;
			return str1;
		}
        int step = 0;				//之字形路径中，表示目前在上下行中走到的位置
		int i=0;
		bool is_down = true;		//表示目前是向下走
		bool is_up = true;
		str_array* str = new str_array[nRows];
		for(int i=0; i<nRows; i++)
			str[i].s = "";
		int temp_row = 0;
		while(i < s.length()) {
			//先往下行
			if(is_down) {
				str[step].s += s[i];
				step++;
				if(step == nRows) {
					//往下每次走nRows步
					is_down = false;
					is_up = true;
					step = 0;
				}
			}
			else if(is_up) {
				str[nRows-step-2].s += s[i];
				step++;
				if(step == nRows-2) {
					//往上每次走nRows-2步
					is_up = false;
					is_down = true;
					step = 0;
				}
			}
			i++;
		}
		string result = "";
		for(int i=0; i<nRows; i++)
			result += str[i].s;
		return result;
    }
};