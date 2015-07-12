//给定一组数字，返回其所有的子集，子集的元素必须以递增形成存在
//思路：
//位操作，遍历it<(1<<n)，对i上为1的位选取对应的元素加入当前子集

class Solution {
public:
	//bool compare(int a, int b) {
	//	return a > b;
	//}
	vector<int> subsets_help(int it, vector<int> &S) {
		vector<int> result;
		int pos = S.size() - 1;
		while(it > 0) {
			if(it % 2 == 1)
				result.push_back(S[pos]);
			it /= 2;
			pos--;
		}
		return result;
	}
    vector<vector<int> > subsets(vector<int> &S) {
		vector<vector<int> > result;
		vector<int> empty;
		empty.clear();
		result.push_back(empty);
		if(S.empty())
			return result;
		sort(S.begin(), S.end());
		reverse(S.begin(), S.end());
		int it = 1;
		while(it < (1 << S.size())) {
			vector<int> tmp = subsets_help(it, S);
			result.push_back(tmp);
			it++;
		}
		return result;
    }
};