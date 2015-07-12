#include<iostream>
#include<vector>
#include<set>
#include<string>
#include<unordered_set>
#include <stdint.h>
using namespace std;

// 给定一个无符号整数，将其二进制表示的所有位取反，求取反后的无符号整数
// 思路：逐位加即可


class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t tmp = 1 << 31;
		uint32_t ret = 0;
		while(n > 0) {
			if(n & 0x01)
				ret += tmp;
			tmp = tmp >> 1;
			n = n >> 1;
		}
		return ret;
    }
};


int main() {
	Solution so;
	cout << so.reverseBits(43261596) << endl;

	system("pause");
	return 0;
}