#include<iostream>
#include<vector>
#include<set>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n != 0) {
	        if((n & 0x01) == 1) {
	        	count++;
	        }
	        n = n >> 1;
	    }
	    return count;
    }
};