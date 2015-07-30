// 有N个加油站，每个加油站有gas[i]的油；一辆车从第i个加油站到第i+1个加油站耗油量为cost[i]；
// 可以从任意一个加油站开始，车的初始油量为0，如果可能走完一圈，则返回开始加油站的编号；不行的话返回-1
//	思路：
//		从0开始，向前走，如果一直走到结尾，再每个点的剩余油量都大于等于0，则可以成功
//		如果到某个点油量变为负的，则重新选择下一个点为起点；如果以往，如果走了两圈都不成功，则返回-1
//		如果中间某个点开始能走完一圈，则成功
//		因此需要两个计数，一个表示总共走了多少个点，一个表示以start为起点成功走了多少个点

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		if(gas.size() == 0)
			return 0;
		if(gas.size() == 1) {
			if(gas[0] < cost[0])
				return -1;
			else
				return 0;
		}

		int successCount = 0;
		int wholeCount = 0;
		int len = gas.size();
		int start = 0;
		int i = 0;
		int left = 0;
		while(wholeCount <= 2 * len) {
			left += gas[i] - cost[i];
			if(left < 0) {
				// 小于0，说明以start为起点无法走完，则重新定义start
				start = (i + 1) % len;
				left = 0;
				successCount = 0;
			}
			else {
				// 大于等于0，说明以start为起点可以走到当前点，则判断successCount是否达到要求了
				if(successCount >= len)
					return start;
				successCount++;
			}
			wholeCount++;
			i = (i + 1) % len;
		}
		return -1;
    }
};

// 另一种思路，遍历一遍即可
//	保存每个点的剩余的油量，并保存剩余最小油量的那个点
//	如果最终油量大于0，说明可以走完，且以剩余最小油量的那个店的下一个点为起始点就可以走完全程

int canCompleteCircuit(int* gas, int gasSize, int* cost, int costSize) {
    int sum=0,minsum=0,minind=-1,i;
    for(i=0;i<gasSize;i++)
    {sum=sum+*(gas+i)-*(cost+i);
       if(sum<minsum)
       {minsum=sum;
          minind=i ;
       } }
       if(sum<0)return -1;
       return minind+1;  
}