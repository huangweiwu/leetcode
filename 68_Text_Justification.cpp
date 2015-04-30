//文本对齐
//给定一组单词和一个长度L，进行左右对齐，要求如下：
//1） 每一行容纳尽可能多的单词
//2） 除了最后一行之外，其他行都左右对齐，长度不足L的用空格补足
//3） 单词间的空格要尽可能一样多，无法平均分配时左边的要比右边的多
//4） 最后一行只需要左对齐
//思路：
//每行凑齐几个单词，计算出需要补足的空格
//结果：Memory Limit Exceeded

class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
        vector<string> result;
		result.clear();
		if(words.size() == 0)
			return result;
		int begin = 0;
		int end = 0;
		bool flag = false;
		while(1) {
			int i = begin;
			int len = 0;		//每一行几个单词的总长度
			int left_len = L;	//每一行剩余的长度
			int num = 0;		//每一行所能单词总数
			while(1) {
				if(left_len >= words[i].length()) {
					len += words[i].length();
					num++;
					left_len -= words[i].length();
					left_len -= 1;
					i++;
					if(i == words.size()) {
						flag = true;
						break;
					}
				}
				else
					break;
			}
			if(flag)
				break;
			end = i;
			string tmp = "";
			//如果该行只有一个单词，则左对齐
			if(num == 1) {
				tmp += words[begin];
				for(int k=words[begin].size(); k<L; k++)
					tmp += " ";
				result.push_back(tmp);
				continue;
			}
			int extra = (L-len) % (num-1);		//需要补足的空格中，左边需要多出的空格数
			for(int j=begin; j<end-1; j++) {
				int space_num = (L-len) / (num-1);
				tmp += words[j];
				while(space_num--)
					tmp += " ";
				if(extra) {
					tmp += " ";
					extra--;
				}
			}
			//再加上最后一个单词
			tmp += words[end-1];
			result.push_back(tmp);
			begin = end;
		}
		string tmp = "";
		for(int k=begin; k<words.size(); k++)
			tmp += words[k];
		while(tmp.length() < L)
			tmp += " ";
		result.push_back(tmp);
		return result;
    }
};


//下面这个AC
//需要注意最后一行的处理以及何时跳出循环等问题
class Solution {
public:
    vector<string> fullJustify(vector<string> &words, int L) {
		if(words.size() == 0)
			return words;
		int begin = 0;
		int end = 0;
		bool flag = false;
		while(1) {
			int i = begin;
			int len = 0;		//每一行几个单词的总长度
			int left_len = L;	//每一行剩余的长度
			int num = 0;		//每一行所能单词总数
			while(1) {
				if(left_len >= words[i].length()) {
					len += words[i].length();
					num++;
					left_len -= words[i].length();
					if(left_len > 0)
						left_len -= 1;
					i++;
					if(i == words.size()) {
						flag = true;
						break;
					}
				}
				else
					break;
			}
			if(flag)
				break;
			end = i;
			string tmp = "";
			//如果该行只有一个单词，则左对齐
			if(num == 1) {
				tmp += words[begin];
				for(int k=words[begin].size(); k<L; k++)
					tmp += " ";
				words[begin] = tmp;
				begin += 1;
				continue;
			}
			int extra = (L-len) % (num-1);		//需要补足的空格中，左边需要多出的空格数
			for(int j=begin; j<end-1; j++) {
				int space_num = (L-len) / (num-1);
				tmp += words[j];
				while(space_num--)
					tmp += " ";
				if(extra) {
					tmp += " ";
					extra--;
				}
			}
			//再加上最后一个单词
			tmp += words[end-1];
			words[begin] = tmp;
			words.erase(words.begin()+begin+1, words.begin()+end);
			begin += 1;
		}
		string tmp = "";
		for(int k=begin; k<words.size(); k++) {
			if(words[k] == "")
				continue;
			tmp += words[k];
			if(tmp.length() == L)
				break;
			tmp += " ";
		}
		while(tmp.length() < L)
			tmp += " ";
		words[begin] = tmp;
		words.erase(words.begin()+begin+1, words.end());
		return words;
    }
};