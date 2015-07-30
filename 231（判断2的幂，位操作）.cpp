// 判断一个数是否2的指数
//	思路：计算n的二进制表示中1的个数
//		个数大于1则返回false
//	注意：小于等于0的情况

class Solution {
public:
    bool isPowerOfTwo(int n) {
		if(n <= 0)
			return false;
		int count = 0;
        for(int i=0, mask=1; i<32; mask<<=1, i++) {
			if(n & mask)
				count++;
			if(count > 1)
				return false;
		}
		return true;
    }
};