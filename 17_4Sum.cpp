//跟之前3Sum的思路一样，不过要多一层的遍历，从而时间复杂度为O(n^3)，先排序，然后遍历num[i]+num[j]
//k=j+1, l=num.size()-1;从两边向中间靠拢
//且要注意不出现重复的问题
//另外在遍历i、j的时候，可以通过判断其是否等于前一个遍历过的节点，是的话直接跳过

class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
		vector<vector<int> > result;
		result.clear();
		int len = num.size();
		if(len>=0 && len<=3)
			return result;
		sort(num.begin(), num.end());
		vector<int> temp;
		temp.clear();
		for(int i=0; i< num.size()-3; i++) {
			if(i!=0 && num[i]==num[i-1])
			//跳过相同的数的遍历
				continue;
			for(int j=i+1; j<num.size()-2; j++) {
				if(j!=i+1 && num[j]==num[j-1])
					continue;
				int k = j + 1;
				int l = num.size() - 1;
				while(k<l) {
					int threesum = num[i]+num[j]+num[k];
					if(threesum+num[l] == target) {
						temp.push_back(num[i]);
						temp.push_back(num[j]);
						temp.push_back(num[k]);
						temp.push_back(num[l]);
						result.push_back(temp);
						temp.clear();
						l--;
						k++;
						while(k<l && num[l]==num[l+1])
							l--;
						while(k<l && num[k]==num[k-1])
							k++;
					}
					else if(threesum+num[l] > target)
						l--;
					else
						k++;
				}
			}
		}
		return result;
    }
};