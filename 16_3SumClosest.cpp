class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
		int result = 0;
		int len = num.size();
		if(len>=0 && len<=2)
			return result;
		sort(num.begin(), num.end());
		result = num[0] + num[1] + num[2];				//给初始化一个result
		for(int i=0; i< num.size()-2; i++) {
			if(i>0 && num[i]==num[i-1])
			//跳过相同的数的遍历
				continue;
			int j = i + 1;
			int k = num.size() - 1;
			while(j < k) {
				int sum = num[i] + num[j] + num[k];
				if(abs(sum-target) < abs(result-target))
					result = sum;
				if(sum == target)
				//如果和等于目标，则直接返回
					return sum;
				else if(sum < target) {
				//如果和小于目标，则负数向前移
					j++;
					while(j<k && num[j]==num[j-1])
						j++;
				}
				else {
				//如果和大于目标，则正数向后移
					k--;
					while(j<k && num[k]==num[k+1])
						k--;
				}
			}
		}
		return result;
    }
};