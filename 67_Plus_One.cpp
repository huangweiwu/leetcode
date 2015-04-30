//一个非负整数用一个序列表示，对这个整数加一
//思路：
//从最低位开始加，并保留进位；直到进位为0或者已经遍历完整数所有的位

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
		int pos = digits.size() - 1;
		while(carry==1 && pos>=0) {
			carry = (digits[pos] + 1) / 10;
			digits[pos] = (digits[pos] + 1) % 10;
			pos--;
		}
		if(carry == 1)
			digits.insert(digits.begin(), 1);
		return digits;
    }
};