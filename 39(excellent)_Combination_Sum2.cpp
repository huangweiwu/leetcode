//和上一题的区别是这里每个元素最多只能使用一次，因此需要稍作修改
class Solution {
private:
	vector<vector<int> > ret;
	vector<int> a;
public:
	void solve(int dep, int maxDep, vector<int> &num, int target) {
		if(target < 0)
			return;
		if(dep == maxDep) {
			if(target == 0) {
				vector<int> tmp;
				for(int i=0; i<maxDep; i++)
					for(int j=0; j<a[i]; j++)
						//对于每个位置i，有a[i]个元素
						tmp.push_back(num[i]);
				ret.push_back(tmp);
			}
			return;
		}
		for(int i=0; i <= min(target/num[dep], 1); i++) {
			//对于每一个元素，其元素个数不能超过1，即为0或1
			a[dep] = i;

			if(i == 1 && dep > 0 && num[dep-1] == num[dep] && a[dep-1] == 0)
				//重复元素的情况
				continue;

			solve(dep + 1, maxDep, num, target - num[dep] * i);
		}
	}
    vector<vector<int> > combinationSum2(vector<int> &num, int target) {
		sort(num.begin(), num.end());
		a.resize(num.size());
		ret.clear();
		if(num.size() == 0)
			return ret;

		solve(0, num.size(), num, target);
		return ret;
    }
};