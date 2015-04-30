//给定一个排好序的数组，返回元素在数组中的位置，如果不存在则返回其插入的位置

class Solution {
public:
    int searchInsert(int A[], int n, int target) {
        for(int i=0; i<n; i++) {
			if(A[i] == target)
				return i;
			if(i==0 && A[i]>target)
				return 0;
			if(i==n-1 && A[i]<target)
				return n;
			if(A[i-1]<target && A[i]>target)
				return i;
		}
    }
};