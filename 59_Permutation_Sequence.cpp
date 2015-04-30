//给定一个数字n，表示[1, 2, ..., n]这些数字钟组成的全排列
//从中找到第k个组合
//思路：利用nextPermutation查找
//结果：超时

class Solution {
public:
	void nextPermutation(vector<int> &num) {
        //5,4,7,5,3,2
        //    |     |
        //    i     j
        //5,5,7,4,3,2
        //5,5,2,3,4,7
        int i = num.size()-1;
        while(i > 0 && num[i-1] >= num[i] ){
            i--;
        }
        int j = i;
        if(i == 0){
            reverse(num.begin(), num.end());
			return ;
        }
        while(j < num.size() && num[j] > num[i-1]) j++;
        
        
            swap(num[i-1], num[j-1]);
            reverse(num.begin() + i, num.end());
    }
	int factorial(int n){  
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;  
    }  
    string getPermutation(int n, int k) {
        vector<int> num(n);
		for(int i=0; i<n; i++)
			num[i] = i+1;
		int tmp = factorial(n);
		k = k % tmp;
		for(int i=1; i<k; i++)
			nextPermutation(num);
		string result = "";
		for(int i=0; i<n; i++)
			result += (num[i] + 48);
		return result;
    }
};

//思路：利用全排列的思想，先将当前去掉，然后考虑剩下的n-1位能表示多少排列组合
//k-1/factorial(n-1)向上取整即可得到当前位置的字符
//k-1是为了保证当k能整除factorial时也刚好取到整数
//另外要注意的是：从字符串中去掉当前已经确定的字符，在后续的字符选择中，应将已经确定的字符排除在考虑范围之外

class Solution {
public:
	int factorial(int n){  
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;  
    }  
    string getPermutation(int n, int k) {
        vector<int> num(n);
		for(int i=0; i<n; i++)
			num[i] = i+1;
		//int tmp = factorial(n);
		//cout << tmp << endl;
		//k = k % tmp;
		string result = "";
		bool is_used[10];
		for(int i=1; i<10; i++)
			is_used[i] = false;
		int t = n;
		while(t) {
			int cur = (k-1) / factorial(t-1) + 1;
			int temp = 0;
			for(int j=1; j<=n; j++) {
				if(!is_used[j])
					temp++;
				if(temp == cur) {
					is_used[j] = true;
					result += (char)(j+48);
					break;
				}
			}
			k -= (cur-1) * factorial(t-1);
			t--;
		}
		return result;
    }
};

