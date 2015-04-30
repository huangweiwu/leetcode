//给定一组正整数数组，初始位置为数组的第一位
//数组中的每一个元素表示从当前位置能跳的最大长度
//目标是使用最少的跳数到达数组的最后一位
//例：A=[2, 3, 1, 1, 4]，则需要两次，先从第0位跳到第1位，再从第1位跳到最后一位
//思路1：
//动态规划
//dp[i] = min{dp[j]+1}，对于每一个j>i，且j-i<=A[i]，即i/j的距离不能超过A[i]
//需要考虑一点，如果A[i]==0，则表示从该点开始不能到达最终节点
//出错：时间复杂度过高

class Solution {
public:
    int jump(int A[], int n) {
        int result;

		int *dp = new int[n];
		memset(dp, 0, n*sizeof(int));

		for(int i=n-2; i>=0; i--) {
			if(A[i] == 0)
				dp[i] = 10000;		//赋予一个很大的值，表示不能到达最后一位
			dp[i] = dp[i+1]+1;
			for(int j=i+2; j<=i+A[i] && j<n; j++) {
				if(dp[j]+1 < dp[i])
					dp[i] = dp[j] + 1;
			}
		}

		return dp[0];
    }
};

//给定一组正整数数组，初始位置为数组的第一位
//数组中的每一个元素表示从当前位置能跳的最大长度
//目标是使用最少的跳数到达数组的最后一位
//例：A=[2, 3, 1, 1, 4]，则需要两次，先从第0位跳到第1位，再从第1位跳到最后一位
//思路2：
//从前往后推，求出到达每个位置所需要的最短跳数
//遍历i，对所有的i+j位置进行更新，j=1, ..., A[i]
//结果：超时
//改进：不用对所有的j都进行改进，对于前面已经更新过的所有位置j，在本轮中就不用更新了
//因此保留前面更新过的最远位置
//如此一来，对于需要更新的位置也不需要进行取小操作，直接dp[i+j] = dp[i] + 1;  

class Solution {
public:
    int jump(int A[], int n) {
        int result;

		int *dp = new int[n];
		memset(dp, 0, n*sizeof(int));
		int max = 0;

		for(int i=0; i<n; i++) {
			for(int j = max - i + 1; j <= A[i]&& i + j < n; j++) {  
				dp[i+j] = dp[i] + 1;  
			}
			max = max > A[i] + i ? max : A[i] + i;
		}
		return dp[n - 1];
    }
};