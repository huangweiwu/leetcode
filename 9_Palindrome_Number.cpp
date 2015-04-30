//判断一个整数是否回文整数，且不能有多余的空间
//需要注意的问题
//1） 负整数不可能是回文整数
//2） 不能使用多余空间
//思路：先求得该数的base（即最高位所在位置），然后每次提取最高位和最低位进行比较
//注意base必须是long long类型的



class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
			return false;
		long long base = 10;
		while(x/base != 0) {
			//求得x的最高位
			base *= 10;
		}
		base /= 10;
		int left = 0, right = 0, i=1;
		while(x!=0) {
			//每次取出最高位和最低位进行比较
			left = x/base;
			right = x%((int)pow((float)10, i));
			if(left != right)
				return false;
			x = x - left*base - right*((int)pow((float)10, i-1));
			x /= 10;
			base /= 100;
		}
		return true;
    }
};