//给定一个数组和一个数elem，删除数组中所有与elem相等的元素
//思路
//记录与elem相等的元素个数count，遍历数组，判断是否与elem相等
//1） 相等，则count++
//2)  不相等，则前移count位

class Solution {
public:
    int removeElement(int A[], int n, int elem) {
        int count = 0;
		for(int i=0; i<n; i++) {
			if(A[i] == elem)
				count++;
			else
				A[i-count] = A[i];
		}
		return n-count;
    }
};