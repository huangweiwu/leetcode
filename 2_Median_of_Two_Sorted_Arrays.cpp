//查找两个已经排序好的数组的中位数
//如果A或者B为空，则直接返回B[k-1]或者A[k-1]；
//如果k为1，我们只需要返回A[0]和B[0]中的较小值；
//如果A[k/2-1]=B[k/2-1]，返回其中一个；

class Solution {
public:
	double find_k_th(int a[], int m, int b[], int n, int k) {
		//求两个数组的第k小值
		if(m > n)
			//使得m总是小于或等于n
			return find_k_th(b, n, a, m, k); 
		if(m == 0)
			//如果m为0，则相当于求数组b中的中位数，直接返回即可
			return b[k-1];
		if(k == 1)
			//k为1，当且仅当m=n=1，则返回两者之间较小的，而不是直接返回平均值，取平均在原函数中已经实现
			return min(a[0], b[0]);
		//将k分割为两部分，取pa为k/2与m的最小值是因为数组a长度不一定大于等于k/2
		int pa = min(k/2, m);
		int pb = k - pa;
		if(a[pa-1] < b[pb-1])
			//如果上述条件成立，则数组a中前面的元素均比b[pb-1]小，可以去掉了，并求第k-pa最小值
			return find_k_th(a+pa, m-pa, b, n, k-pa);
		else if(a[pa-1] > b[pb-1])
			return find_k_th(a, m, b+pb, n-pb, k-pb);
		else
			//如果相等，则说明第k小元素已经找到
			return a[pa-1];
	}
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        int total = m + n;
		if( total & 0x01) 
			//如果是奇数
			return find_k_th(A, m, B, n, (total+1)/2);
		else
			//如果是偶数
			return (find_k_th(A, m, B, n, total/2) + find_k_th(A, m, B, n, total/2+1)) / 2;
    }
};