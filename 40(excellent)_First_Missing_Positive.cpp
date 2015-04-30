//给定一没排好序的整型数组，找到第一个丢失的正数
//要求：时间复杂度为O(n)，空间复杂度为O(1)
//思路：
//对于所有大于等于0，小于n的数A[i]，将其交换到位置i
//之后再遍历数组，哪个位置i上没有对应的A[i] == i，则返回i
//数组A有两个特殊情况：
//1） 0, 1, 2, ...交换后依然是0, 1, 2, ...，需返回n
//2） 1, 2, 3, ...交换后变成了n, 1, 2, ...，需返回n+1

class Solution {
public:
    int firstMissingPositive(int A[], int n) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int i = 0;
        while(i < n)
        {
            if (A[i] == i)
                i++;
            else
            {
                if (0 <= A[i] && A[i] < n && A[A[i]] != A[i])
                {
                    int t = A[i];
                    A[i] = A[A[i]];
                    A[t] = t;
                    continue;
                }
                else
                    i++;
            }
        }
        
        for(int i = 1; i < n; i++)
            if (A[i] != i)
                return i;
        
        return A[0] == n ? n + 1 : n;
    }
};