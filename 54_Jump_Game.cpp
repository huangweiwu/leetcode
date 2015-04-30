//给定一个非负数组，每个数代表在该位置向后的最大跳数
//初始位置在数组的首部，判定是否能达到数组的末端
//从后往前推，isreach[i]表示从位置i开始是否能到达末端
//isreach[i]>0表示能到达，isreach[i]<=0表示不能到达
//isreach[i] == sum{isreach[j]}, i+1 < j < i+A[i]
//结果：时间复杂度过高
class Solution {
public:
    bool canJump(int A[], int n) {
		bool *isreach = new bool[n];
		memset(isreach, 0, sizeof(bool)*n);
		isreach[n-1] = true;

		for(int i=n-2; i>=0; i--) {
			for(int j=i+1; j<=i+A[i]; j++)
				if(isreach[j]) {
					isreach[i] = true;
					break;
				}
		}

		return isreach[0];
    }
};


//给定一个非负数组，每个数代表在该位置向后的最大跳数
//初始位置在数组的首部，判定是否能达到数组的末端
//维持变量step，遍历数组
//使变量step一直保持最大的能移动步数
//初始值step = A[0]
//当移动到新的位置i, step--, step = max(step, A[i])
//如果step>0则继续，如果step<=0则返回FALSE
//时间复杂度O(n)

class Solution {
public:
    bool canJump(int A[], int n) {
		int step = A[0];
		for(int i = 1; i < n; i++) {
			if(step > 0) {
				step--;
				step = max(step, A[i]);
			}
			else
				return false;
		}
		return true;
    }
};