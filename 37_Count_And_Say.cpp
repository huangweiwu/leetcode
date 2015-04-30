//第一个字符串为"1"，以后每一个字符串都是数前一个字符串的数字个数
//例子：第二个字符串为11，表示前一个数有一个1
//		第三个字符串为21，表示前一个数有两个1
//		第四个字符串为1211，表示前一个数有一个2，一个1
//给定一个数字n，给出第n个字符串

//思路：
//递归对前一个数进行计数操作并输出
//n为1时返回"1"，n为2时返回"21"
class Solution {
public:
	string itostring(int n) {
		string result = "";
		while(n) {
			int tmp = n % 10;
			char ch = tmp + 48;
			result += ch;
			n /= 10;
		}
		reverse(result.begin(), result.end());
		return result;
	}
	string countAndSayHelp(int n) {
		string result = "";
		if(n == 1) {
			result = "1";
			return result;
		}
		else if(n == 2) {
			result = "11";
			return result;
		}
		else {
			string str = countAndSayHelp(n-1);
			int temp_count = 1;
			for(int i=1; i<str.length(); i++) {
				if(str[i] == str[i-1])
					temp_count++;
				else {
					result += itostring(temp_count);
					result += str[i-1];
					temp_count = 1;
				}
			}
			result += itostring(temp_count);
			result += str[str.length()-1];
			return result;
		}
	}
    string countAndSay(int n) {
        return countAndSayHelp(n);
    }
};