//给定一组排好序的数组，查找一个元素在数组中的起点和终点

class Solution {
public:
    vector<int> searchRange(int A[], int n, int target) {
		vector<int> result;
		result.clear();
		int start = -1;
		int end = -1;
		int k =1;				//标记是第一个数还是第二个数
        for(int i=0; i<n; i++) {
			if(A[i] == target) {
				if(k++ == 1)
					start = i;
				end = i;
			}
		}
		result.push_back(start);
		result.push_back(end);
		return result;
    }
};