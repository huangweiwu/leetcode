//给一个数字n，表示n对圆括号，给出所有可能的组合
//例如n=3时有这些组合，"((()))", "(()())", "(())()", "()(())", "()()()"

//思路：递归考虑剩下的左括号和右括号的个数，leftNum和rightNum
//如果leftNum大于零，则直接将"("打印出来
//如果rightNum大于零且leftNum<rightNum，则可以将")"打印出来
//如果leftNum和rightNum都等于零，则将打印出来的字符串存储起来

class Solution {
public:
	void generateParenthesis_help(int leftNum, int rightNum, string str, vector<string> &result) {
		if(leftNum==0 && rightNum==0)
			result.push_back(str);
		if(leftNum > 0)
			generateParenthesis_help(leftNum-1, rightNum, str+"(", result);
		if(rightNum>0 && rightNum>leftNum)
			//每次上面从递归返回后，字符串str又变回原来的str，因此能遍历所有的情况
			generateParenthesis_help(leftNum, rightNum-1, str+")", result);
	}
    vector<string> generateParenthesis(int n) {
		vector<string> result;
        int leftNum = n;
		int rightNum = n;
		string str = "";
		generateParenthesis_help(leftNum, rightNum, str, result);
		return result;
    }
};