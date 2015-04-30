//给定两个二进制字符串，进行加法操作
//思路：
//从最低位开始加起，保存进位carry，注意遍历完两个字符串后，还需要考虑carry是否为1

class Solution {
public:
	vector<int> myadd(int ch1, int ch2, int carry) {
		vector<int> result;
		int tmp = ch1 + ch2 + carry;
		switch(tmp) {
		case 0:
			result.push_back(0);
			result.push_back(0);
			break;
		case 1:
			result.push_back(1);
			result.push_back(0);
			break;
		case 2:
			result.push_back(0);
			result.push_back(1);
			break;
		case 3:
			result.push_back(1);
			result.push_back(1);
			break;
		}
		return result;
	}
    string addBinary(string a, string b) {
		if(a.length() == 0)
			return b;
		if(b.length() == 0)
			return a;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int i = 0;
		int j = 0;
		string result = "";
		int carry = 0;
		while(i<a.length() && j<b.length()) {
			vector<int> tmp = myadd(a[i]-48, b[j]-48, carry);
			result += (char)(tmp[0] + 48);
			carry = tmp[1];
			i++;
			j++;
		}
		if(i == a.length()) {
			while(j < b.length()) {
				int t = 0;
				vector<int> tmp = myadd(t, b[j]-48, carry);
				result += (char)(tmp[0] + 48);
				carry = tmp[1];
				j++;
			}
		}
		if(j == b.length()) {
			while(i < a.length()) {
				int t = 0;
				vector<int> tmp = myadd(a[i]-48, t, carry);
				result += (char)(tmp[0] + 48);
				carry = tmp[1];
				i++;
			}
		}
		if(carry == 1)
			result += "1";
		reverse(result.begin(), result.end());
		return result;
    }
};