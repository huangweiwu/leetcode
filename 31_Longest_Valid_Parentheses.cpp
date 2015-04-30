//给定仅包含"("和")"的一个字符串，查找最长的有效子串
//思路：
//从左到右以及从右到左各遍历一遍，统计左括号和右括号的总数
//当左括号数变为小于右括号数，两个都清零，且max_len等于当前两个数的总和
//当左括号数等于右括号数时，更新max_len

class Solution {
public:
    int longestValidParentheses(string s) {
        int result = 0;
		int left = 0;
		int right = 0;
		for(int i=0; i<s.length(); i++) {
			if(s[i] == '(')
				left++;
			else 
				right++;
			if(right > left)
				//右括号数超过左括号数
				left = right = 0;
			if(right==left) {
				//如果到最后一步，刚好左括号数等于右括号数
				int temp = 2 * right;
				result = temp>result?temp:result;
			}
		}
		left = right = 0;
		for(int i=s.length()-1; i>=0; i--) {
			if(s[i] == '(')
				left++;
			else 
				right++;
			if(left > right)
				left = right = 0;
			if(right==left) {
				//如果到最后一步，刚好左括号数等于右括号数
				int temp = 2 * right;
				result = temp>result?temp:result;
			}
		}
		return result;
    }
};
