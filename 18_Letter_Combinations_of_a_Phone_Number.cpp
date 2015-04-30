//给定一串数字，看该串数字在手机键盘中能表示的字符串个数
//思路：将数字键逐个遍历其字母，添加进当前结果，当前结果保存的是目前已经遍历过的数字键所有的组合

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> result;
		result.clear();
		string temp_str = "";
		if(!digits.length()) {
			//如果长度为零，则返回空的
			result.push_back(temp_str);
			return result;
		}
		vector<string> num_digit;
		num_digit.push_back("abc");
		num_digit.push_back("def");
		num_digit.push_back("ghi");
		num_digit.push_back("jkl");
		num_digit.push_back("mno");
		num_digit.push_back("pqrs");
		num_digit.push_back("tuv");
		num_digit.push_back("wxyz");
				
		for(int i=0; i<num_digit[digits[0]-50].length(); i++) {
			//先将第一个数字所能表示的字母存储起来
			temp_str += num_digit[digits[0]-50][i];
			result.push_back(temp_str);
			temp_str = "";
		}
		int t=1;
		while(t<digits.length()) {
			vector<string> temp_result(result);
			result.clear();
			for(int j=0; j<temp_result.size(); j++)	{
				for(int k=0; k<num_digit[digits[t]-50].length(); k++) {
					temp_str += temp_result[j];
					temp_str += num_digit[digits[t]-50][k];
					result.push_back(temp_str);
					temp_str = "";
				}
			}
			t++;
		}
		return result;
    }
};