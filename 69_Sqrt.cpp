//求一个数的平方根
//思路：
//二分搜索
//注意int类型数据相乘后数挺大，进行大小比较时需转化为无符号长整型

class Solution {
public:
	bool issqrt(int t, int x) {
		unsigned long long tmp = (unsigned long long)x;
		unsigned long long left = (unsigned long long)t * (unsigned long long)t;
		unsigned long long right = (unsigned long long)(t+1) * (unsigned long long)(t+1);
		if(left<=tmp && right>tmp)
			return true;
		else
			return false;
	}
	int binary_search(unsigned begin, unsigned end, unsigned x) {
			unsigned mid = (begin + end) / 2;
			if(issqrt(mid, x))
				return mid;
			else {
				if((unsigned long long)mid*mid > (unsigned long long)x)
					return binary_search(begin, mid, x);
				else
					return binary_search(mid, end, x);
			}
	}
    int sqrt(int x) {
        return binary_search(1, x, x);
    }
};