// 给定一个表达式，计算所有在不同位置加上括号的表达式的结果
//	思路：在任意运算符位置将表达式分割成两部分求值；当只剩下一个数字的时候返回数字

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> ret;
		for(int i=0; i<input.length(); i++) {
			if(ispunct(input[i])) {
				for(auto a : diffWaysToCompute(input.substr(0, i)))
					for(auto b : diffWaysToCompute(input.substr(i+1)))
						ret.push_back(input[i] == '+' ? a + b : input[i] == '-' ? a - b : a * b);
			}
		}
		return ret.size() ? ret : vector<int>{stoi(input)};
    }
};

int main() {
	Solution so;
	
	string sss = "2";
	vector<int> ret = so.diffWaysToCompute(sss);

	system("pause");
	return 0;
}