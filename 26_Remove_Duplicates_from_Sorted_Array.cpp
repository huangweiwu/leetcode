//将一组排好序的数组删除重复的元素，并返回新数组的长度
//要求：不能分配一个新的数组空间，空间复杂度为O(1)
//思路：
//记录数组长度n，往前移的长度len=0，每次往前移的时候要同时判断与前一个元素是否相等
//相等则len++
//不相等则往前移len位
//时间复杂度为O(n)，空间复杂度为O(1)

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		int len = 0;
        for(int i=1; i<n; i++) {
			if(A[i] == A[i-len-1]) {
				len++;
			}
			else
				A[i-len] = A[i];
		}
		return n-len;
    }
};