//在一个旋转过的数组里查找元素，找到元素则返回其在原数组中的index，否则返回-1

class Solution {
public:
    int search(int A[], int n, int target) {
		int pivot = 0;			//循环右移的位数
		int pos = 0;			//保存在旋转数组中的位置
		bool flag = false;
        for(int i=0; i<n; i++) {
			if(A[i] == target) {
				flag = true;
				pos = i;
			}
			if(i==0 && A[i]>A[i+1])
				pivot = i;
			else if(i!=n-1 && A[i]>A[i-1] && A[i]>A[i+1]) 
				pivot = i;
		}
		if(!flag)
			return -1;
		int result = pos % n;
		return result;
    }
};
