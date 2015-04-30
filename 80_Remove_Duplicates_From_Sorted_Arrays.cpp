//删除已排好序的数组里的重复项，重复项最多为2
//思路：
//遍历数组，将每个数的超过2的去掉

class Solution {
public:
    int removeDuplicates(int A[], int n) {
		vector<int> a;
		int tmpcount = 1;
        for(int i=1; i<n; i++) {
			if(A[i] == A[i-1])
				tmpcount++;
			else {
				if(tmpcount > 2) {
					a.push_back(A[i-1]);
					a.push_back(A[i-1]);
				}
				else {
					for(int j=0; j<tmpcount; j++)
						a.push_back(A[i-1]);
				}
				tmpcount = 1;
			}
		}
		if(tmpcount > 2) {
			a.push_back(A[n-1]);
			a.push_back(A[n-1]);
		}
		else {
			for(int j=0; j<tmpcount; j++)
				a.push_back(A[n-1]);
		}
		for(int i=0; i<a.size(); i++)
			A[i] = a[i];
		if(a.size() < n)
			A[a.size()] = '\0';
		return a.size();
    }
};