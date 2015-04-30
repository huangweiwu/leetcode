//给定n,k
//n表示1, 2, ..., n，从这n个数中返回所有长度为k的组合
//思路：
//递归往结果中添加元素，类似dfs的思想

class Solution {
private:
    vector<vector<int> > ret;
	vector<int> tmp;
public:
	void solve(int dep, int maxdep, int n, int start) {
		if(dep == maxdep) {
			ret.push_back(tmp);
			return;
		}
		
		for(int i=start; i<=n; i++) {
			tmp[dep] = i;
			solve(dep+1, maxdep, n, i+1);
		}
	}
    vector<vector<int> > combine(int n, int k) {
		tmp.resize(k);
		solve(0, k, n, 1);
		return ret;
    }
};