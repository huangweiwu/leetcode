//实现pow(x, n)
//思路：
//要考虑一些条件
//1） n是否为0
//2） n的正负性
//3） x的绝对值是否为1

class Solution {
public:
    double pow(double x, int n) {
        double result = 1;
		if(x==result || n==0)
			return result;
		if(x==-result) {
			int ss = n %2 ;
			if(ss)
				return x;
			else
				return -x;
		}
		bool flag = true;
		if(n < 0) {
			flag = false;
			n = -n;
		}
		while(n-- && result)
			result *= x;
		return flag ? result : 1/result;
    }
};