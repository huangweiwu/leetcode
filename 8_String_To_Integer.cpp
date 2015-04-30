//实现一个字符串到整数的转换
//要考虑的情况
//1） 字符串前面有很多空字符，要跳过直到第一个非空字符出现
//2） 第一个有意义的字符必须是+/-或者直接从数字开始，如果不是的话则不予转换；此外，翻译的长度从第一个有意义的字符开始到一个非数字字符出现为止
//3） 字符串为空或者仅有空字符，或者第一个字符为非有意义字符不予转换，返回零
//4） 整数的范围为-2147483648~2147483647，超出该范围则输出对应的最大最小值

//思路
//1） 先将字符串做预处理，返回有意义的字符串
//2)  对上面的第四步，判断返回的字符串的长度，若长度大于11，则必然超出范围；另外定义一个长整型保存当前运算结果

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string pre_converse(const char *str) {
		string result = "";
		if(str[0] == '\0') 
			//空字符串
			return result;
		bool is_first = true;			//表示是否遇到第一个非空字符
		int i=0;
		while(str[i] != '\0') {
			if(str[i] == ' ') {
				if(!is_first)
					//如果空格不是在前面出现的，则终止
					break;
				i++;
				continue;
			}
			if(is_first) {
				if(str[i]!='+' && str[i]!='-' && str[i]!=' ' && (str[i]<'0' || str[i]>'9'))
					//第一个非空字符非有意义字符
					return result;
				is_first = false;		//后面的字符不是第一个非空字符
				result += str[i];
			}
			else {
				//处理第一个字符后的字符
				if(str[i]<'0' || str[i]>'9')
					//遇到非有意义字符则终止
					break;
				result += str[i];
			}
			i++;
		}
		return result;
	}
    int atoi(const char *str) {
        //先将字符串做预处理
		string s_pre = pre_converse(str);
		if(s_pre.length() == 0)
			return 0;
		if(s_pre.length()==1 && (s_pre[0]=='+' || s_pre[0]=='-'))
			return 0;
		int result = 0;
		int i=0;
		if(s_pre.length()>11) {
			//长度大于十一则肯定超出范围
			if(s_pre[0] == '-') 
				result = -2147483648;
			else
				result = 2147483647;
			return result;
		}
		bool is_first_signal = false;		//表示第一个字符是否是符号
		if(s_pre[0]=='+' || s_pre[0]=='-') {
			is_first_signal = true;
			i++;
		}
		unsigned long long temp = 0;
		for(i; i<s_pre.length(); i++)
			temp += (s_pre[i]-48)*(pow(float(10), s_pre.length()-i-1));
		if(s_pre[0] == '-') {
			if(temp > 2147483648) 
				result = -2147483648;
			else
				result = -temp;
			return result;
		}
		else {
			result = temp>2147483647?2147483647:temp;
			return result;
		}
    }
};