//将一个整数转换成罗马数字，整数范围为1~3999
//罗马数字中有几个基
//I-1	V-5		X-10	L-50	C-100	D-500	M-1000
//且当比较小的基位于比较大的基前面时，表示减法，反之表示加法，如IV表示4，VI表示6
//另外，不能隔位减，例子99为XCIX，而不是IC，因为C不能用于减I，这样属于隔位减

//思路：
//判断每一位上的数，根据每一位的值来确定该位对应的罗马数字

class Solution {
public:
	string each_pos_convert(int value, char low, char high, char carry) {
		//用于每一位的转化，传入的参数包括该为上的数值，以及该位和进一位上的基
		string result = "";
		switch(value) {
		case 1:
			result += low;
			break;
		case 2:
			result += low;
			result += low;
			break;
		case 3:
			result += low;
			result += low;
			result += low;
			break;
		case 4:
			result += low;
			result += high;
			break;
		case 5:
			result += high;
			break;
		case 6:
			result += high;
			result += low;
			break;
		case 7:
			result += high;
			result += low;
			result += low;
			break;
		case 8:
			result += high;
			result += low;
			result += low;
			result += low;
			break;
		case 9:
			result += low;
			result += carry;
			break;
		default:
			break;
		}
		return result;
	}
    string intToRoman(int num) {
        string result = "";
		int temp = 0;		//表示当前位的值
		int i = 3;
		char ch[5][2] = {{'I', 'V'}, {'X', 'L'}, {'C', 'D'}, {'M', 'a'}, {'a', 'a'}};
		while(num) {
			temp = num / (pow((float)10, i));
			if(temp)
				result += each_pos_convert(temp, ch[i][0], ch[i][1], ch[i+1][0]);
			num -= temp * (pow((float)10, i));
			i--;
		}
		return result;
    }
};