//给定n个对象，分类为红、白和蓝三种颜色，分别用值0/1/2进行表示，对他们进行排序
//思路：
//正向遍历数组
//1) 如果值为0，则保持位置不变
//2）如果值为1或者2，则与其后第一个0交换位置
//反向遍历数组
//1）如果值为2，则保持位置不变
//2）如果值为0或者1，则与其后第一个2交换位置


class Solution {
public:
    void sortColors(int A[], int n) {
        for(int i=0; i<n; i++) {
			if(A[i] != 0) {
				for(int j=i+1; j<n ;j++) {
					if(A[j] == 0) {
						int temp = A[i];
						A[i] = A[j];
						A[j] = temp;
						break;
					}
				}
			}
		}
		for(int i=n-1; i>=0; i--) {
			if(A[i] != 2) {
				for(int j=i-1; j>=0; j--) {
					if(A[j] == 2) {
						int temp = A[i];
						A[i] = A[j];
						A[j] = temp;
						break;
					}
				}
			}
		}
    }
};