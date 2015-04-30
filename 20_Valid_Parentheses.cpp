//给定一个仅包含"()[]{}"的字符串，判断是否是有效的字符串
//判断依据
//必须正确的闭合，如"()[]{}"  "([])"都是正确的，"([)]"则是错误的
//思路：将([{称为左字符，)]}称为右字符；将字符一个个读进来
//1） 遇到左字符时，则入栈
//2） 遇到右字符时，则判断栈顶是否有对应的左字符，是的话则将栈顶元素出栈，不是则返回false
//最后当字符串读取完，如果栈为空，则返回true；不为空则返回false

//上面的思路出错了，还需考虑一个情况，即遇到右字符时，需先判断栈是否为空，若为空则直接返回false，然后再进行上面的过程	

class Solution {
public:
	bool is_left_ch(char ch) {
		if(ch=='(' || ch=='[' || ch=='{')
			return true;
		else
			return false;
	}
	bool is_partner(char ch1, char ch2) {
		if((ch1=='('&&ch2==')') || (ch1==')'&&ch2=='(') || (ch1=='['&&ch2==']') || (ch1==']'&&ch2=='[') || (ch1=='{'&&ch2=='}') || (ch1=='}'&&ch2=='{'))
			return true;
		else
			return false;
	}
    bool isValid(string s) {
        vector<char> ch;
		for(int i=0; i<s.length(); i++) {
			if(is_left_ch(s[i]))
				ch.push_back(s[i]);
			else {
				if(ch.empty())
					return false;
				else {
					if(!is_partner(ch[ch.size()-1], s[i]))
						return false;
					else
						ch.pop_back();
				}
			}
		}
		if(ch.empty())
			return true;
		else
			return false;
    }
};