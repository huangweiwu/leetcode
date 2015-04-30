//给定两个用字符串表示的数字
//求两个数字的乘积，数可以使任意大且非负
//思路：
//遍历num2的每一位，与num1的每一位进行相乘，且先不考虑进位，将结果保存为一个vector
//最后对vector中的进位进行处理即可

class Solution {
public:
    string multiply(string num1, string num2) {
		vector<int> res(num1.length() + num2.length(), 0);
		
		int k = 0;				//表示当前已经计算第几位
		for(int i=num2.length()-1; i>=0; i--) {
			for(int j=num1.length()-1; j>=0; j--) {
				res[k+num1.length()-j-1] += (num1[j] - '0') * (num2[i] - '0');
			}
			k++;
		}
		int carry = 0;
		for(int i=0; i<res.size(); i++) {
			int tmp = (res[i] + carry) % 10;
			carry = (res[i] + carry) / 10;
			res[i] = tmp;
		}
		int pos = res.size() - 1;
		while(!res[pos] && pos) {
			//将零位都去掉
			res.pop_back();
			pos--;
		}
		string result = "";
		for(int i=res.size()-1; i>=0; i--)
			result += (char)(res[i] + '0');
		return result;
    }
};