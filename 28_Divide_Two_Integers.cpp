//实现两个数相处，不使用乘法、除法和取余操作符
//思路，用加法，遍历int能表示的整个空间
//加速：
//1） 除数为1或者-1时可以直接返回
//2） 判断除数与被除数的同号性，同号则遍历正数空间的一半，异号则遍历负数空间的一半
//此方法时间复杂度高

class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == 0)
			return -1;
		if(divisor == 1)
			return dividend;
		if(divisor == -1)
			return -dividend;
		if(dividend == 0)
			return 0;
		if((dividend>0&&divisor>0) || (dividend<0&&divisor<0)) {
			//同号遍历正数空间
			long long temp = 0;
			long long pre = 0;
			for(int i=1; i<=1073741824; i++) {
				temp += divisor;
				pre = temp-divisor;
				if(temp == dividend)
					return i;
				else if(pre<dividend && temp>dividend)
					return i-1;
			}
		}
		else {
			long long temp = 0;
			long long pre = 0;
			for(int i=1; i<=1073741824; i++) {
				temp += divisor;
				pre = temp-divisor;
				if(-temp == dividend)
					return -i;
				else if(((-pre)<dividend&&(-temp)>dividend) || ((-pre)>dividend&&(-temp)<dividend))
					return -(i-1);
			}
		}
    }
};


//每个数都可以表示成以2为底的一组基的线性组合，即num=a_0*2^0+a_1*2^1+a_2*2^2+...+a_n*2^n
//因此可以利用移位操作来求得所有不为零的的基，这里的系数a0到an已经全部默认为divisor
class Solution {
public:
    int divide(int dividend, int divisor) {
		if(divisor == 0)
			return -1;
		if(divisor == 1)
			return dividend;
		if(divisor == -1)
			return -dividend;
		int result = 0;
		int flag = 1;			//标记除数与被除数的同号异号性
		if((dividend>0&&divisor<0) || (dividend<0&&divisor>0))
			flag = -1;
		long long abs_dividend = abs((long long)dividend);
		long long abs_divisor = abs((long long)divisor);
		long long temp = 0;

		while(abs_dividend > abs_divisor) {
			int count = 1;		//逐个求基
			temp = abs_divisor;
			while((temp<<=1) <= abs_dividend)
				count<<=1;
			result += count;
			abs_dividend -= (temp>>1);
		}
		return result*flag;
    }
};


//顺便写一下不用乘法求两个数的积
long long add(long long p, long long num) {  
    if(p == 0) {  
        return 0;  
    }  
    long long temp = add(p >> 1, num) << 1;  
    if((p & 1) != 0) {  
        temp += num;  
    }  
    return temp;  
}

long long add(long long num1, long long num2) {
	long long result = 0;
	while(num1 > 0) {
		if((num1&1) != 0)
			//最低位不为零
			result += num2;
		num2 <<= 1;
		num1 >>= 1;
	}
	return result;
}