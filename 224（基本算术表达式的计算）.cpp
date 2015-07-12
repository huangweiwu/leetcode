#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;

// 计算含有加号、减号、空格以及括号的表达式
// 思路：
//	遇到空格将其略过
//	遇到左括号或者加减号，将其入栈
//	遇到数字，判断当前符号栈当前栈顶元素，如果为加减，则取出数字栈的栈顶元素进行相应的操作并将结果入数字栈；如果为左括号，则将其入数字栈
//	遇到右括号，将符号栈的栈顶元素【此时必为左括号】弹出；弹出后需要进一步判断符号栈栈顶是否加减号，是的话要进行相应运算
//	

class Solution {
public:
	stack<int> s1;
	stack<char> s2;
    int calculate(string s) {
		// 找到第一个数字
		int i=0;
		string num = "";
		for(; i<s.length(); i++) {
			if(s[i] == '(')
				s2.push(s[i]);
			if(s[i] != '(' && s[i] != ')' && s[i] != ' ') {
				if(s[i]>='0' && s[i]<='9') {
					num = "";
					while(s[i]>='0' && s[i]<='9') {
						num += s[i];
						i++;
					}
					s1.push(atoi(num.c_str()));
					break;
				}
			}
		}
		for(; i<s.length();) {
			if(s[i] == '(' || s[i] == '+' || s[i] == '-') {
				s2.push(s[i]);
				i++;
			}
			else if(s[i] == ')') {
				s2.pop();
				i++;
				while(!s2.empty() && (s2.top() == '+' || s2.top() == '-')) {
					if(s2.top() == '+') {
						int a2 = s1.top();
						s1.pop();
						int a1 = s1.top();
						s1.pop();
						s1.push(a1+a2);
						s2.pop();
					}
					else if(s2.top() == '-') {
						int a2 = s1.top();
						s1.pop();
						int a1 = s1.top();
						s1.pop();
						s1.push(a1-a2);
						s2.pop();
					}
				}
			}
			else if(s[i]>='0' && s[i]<='9') {
				num = "";
				while(s[i]>='0' && s[i]<='9') {
					num += s[i];
					i++;
				}
				int tmp = atoi(num.c_str());
				if(s2.top() == '(')
					s1.push(tmp);
				else {
					if(s2.top() == '+') {
						tmp += s1.top();
						s1.pop();
						s1.push(tmp);
						s2.pop();
						
					}
					else {
						tmp = s1.top() - tmp;
						s1.pop();
						s1.push(tmp);
						s2.pop();
					}
				}
			}
			else
				i++;
		}
		if(s2.empty())
			return s1.top();
		if(s2.top() == '+') {
			int a2 = s1.top();
			s1.pop();
			int a1 = s1.top();
			return a1 + a2;
		}
		else {
			int a2 = s1.top();
			s1.pop();
			int a1 = s1.top();
			return a1 - a2;
		}
    }
};

int main() {
	Solution so;
	string s = "2-(5-6)";
	cout << so.calculate(s) << endl;

	system("pause");
	return 0;
}