//将一个整数倒序返回
//如123则返回321，-123则返回-321

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        bool is_positive = true;
		if(x < 0) {
			x = -x;
			is_positive = false;
		}
		int* each_pos = new int[32];	//表示各个位上的值
		int i=0;
		while(x) {
			each_pos[i++] = x % 10;
			x /= 10;
		}
		int result = 0;
		for(int k=0; k<i; k++)
			result += each_pos[k] * pow(float(10), i-k-1);
		if(!is_positive)
			result = -result;
		return result;
    }
};