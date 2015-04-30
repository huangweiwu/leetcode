//给定一个数组，数组中的数据表示方形条的高度，求这些数字构成的方形条能装多少水，一格表示1
//思路：
//从第一个位置遍历所有的高度条并维持一个vector，保存当前的起点高度start_height
//遍历所有的位置
//1） 遍历vector中的元素，若当前位置高度比vector中的元素高度均大于start_height，则计算体积；若当前高度比vector中元素高度低或等高，则出栈
//2） 若当前位置高度大于0，则入栈
//时间复杂度过高：Time Limit Exceeded

typedef struct condition {
	//保存的元素包含其位置及高度
	int pos;
	int height;
}cond;

class Solution {
public:
    int trap(int A[], int n) {
        vector<cond> current;
		current.clear();
		int result = 0;
		int start_height = 0;		//当前计算体积时的起点高度
		int i = 0;
		while(A[i] == 0)
			//跳过一开始的零
			i++;
		for(; i<n; i++) {
			for(int j=current.size()-1; j>=0; j--) {

				if(current[j].height>start_height && A[i]>start_height) {
					result += abs(min(current[j].height, A[i])-start_height) * abs(i-current[j].pos-1);
					if(current[j].height <= A[i]) {
						start_height = current[j].height;
						current.pop_back();
					}
					else
						start_height = A[i];
				}
			}
			if(A[i]) {
				//如果没计算过且高度大于零
				cond tmp;
				tmp.pos = i;
				tmp.height = A[i];
				current.push_back(tmp);
			}
			start_height = A[i];
		}
		return result;
    }
};


//每个位置能存储的水取决于其左边最高高度和右边的最高高度，两者较小者减去A[i]即是该位置的储水量
//所以先遍历求得每个位置的左边最高高度以及右边最高高度
//再遍历一遍求总的储水量
//算法时间复杂度和空间复杂度均为O(n)

class Solution {
public:
    int trap(int A[], int n) {
        int result = 0;
		vector<int> leftmosthigh(n);
		vector<int> rightmosthigh(n);

		int maxhigh = 0;
		for(int i=0; i<n; i++) {
			leftmosthigh[i] = maxhigh;
			//更新当前最大值
			maxhigh = maxhigh > A[i] ? maxhigh : A[i];
		}

		maxhigh = 0;
		for(int i=n-1; i>=0; i--) {
			rightmosthigh[i] = maxhigh;
			maxhigh = maxhigh > A[i] ? maxhigh : A[i];
		}

		for(int i=0; i<n; i++) {
			int tmp = min(leftmosthigh[i], rightmosthigh[i]) - A[i];
			if(tmp > 0)
				result += tmp;
		}

		return result;
    }
};