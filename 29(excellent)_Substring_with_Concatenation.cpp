//给定一个字符串和一组单词，在字符串中找出该组单词拼接成的子字符串的位置，拼接顺序没要求
//思路：
//利用STL中的next_permutation来生成所有的排列，注意初始参数数组a[]必须是递增的才能得到所有的排列
//查找子字符串可以使用strstr()，这里自己实现，利用strncmp()进行遍历
//Time Limit Excceeded

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		result.clear();
		int n = L.size();
		int *a = new int[n];
		for(int i=0; i<n; i++)
			a[i] = i;
		int len = L.size()*L[0].length();		//子字符串的总长度
		do {
			string temp = "";
			for(int i=0; i<n; i++)
				temp += L[a[i]];
			const char *src = S.c_str();
			const char *pat = temp.c_str();
			for(int j=0; *src && strlen(src)>=len; src++, j++) {
				if(!strncmp(src, pat, len))
					result.push_back(j);
			}
		}while(next_permutation(a, a+n));
		return result;
	}
};

//确实按照上述方法时间复杂度有点高，对每一个组合都要遍历字符串S一遍，从而时间复杂度为O(len!*n)
//改进：仅遍历字符串S一遍，对于每一位，如果没找到词典数组中的任何一个子串，则前进一位，找到则前进四位，并查找剩下的子串是否连接在后面
//注意的问题
//1） 找到匹配的单词后，要将src的位置回溯到匹配位置的下一个字符
//2） 没有匹配完全的情况下，也需要将src的位置回溯
//这个也有较高的时间复杂度，Time Limit Excceeded
//这个思想和下面提到的窗口思想是一致的
//改进：
//每次能完全匹配，说明跳过len个字符位置开始的地方，已经能匹配L.size()-1个单词，循环对其进行判断，找出所有的位置
//在后面的循环中到达该位置则直接跳过
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		result.clear();
		vector<string> L_copy(L);		//复制一份字典
		int len = L[0].length();		//单词的长度
		int correct = 0;				//记录匹配了几个单词
		const char *src = S.c_str();
		for(int i=0; *src && strlen(src)>=len*L.size(); src++, i++) {
			//i用于记录位置
			vector<string>::iterator iter;
			for(iter=L_copy.begin(); iter!=L_copy.end();) {
				const char *pat = (*iter).c_str();
				if(!strncmp(src, pat, len)) {
					//如果找到了其中一个单词，则将其删除，src += len，j = 0，重新开始本次循环
					L_copy.erase(iter);
					src += len;
					iter = L_copy.begin();
					correct++;
					continue;			//重头开始，跳过iter++
				}
				iter++;
			}
			if(correct==L.size()) {
				//如果最后L_copy空了，说明找到了匹配的位置
				result.push_back(i);
				L_copy = L;
			}
			src -= correct*len;		//找到匹配的之后，src必须回溯到上一个位置的下一个字符位置
			correct = 0;
			L_copy = L;
		}
		return result;
	}
};

class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
		vector<int> result;
		result.clear();
		vector<string> L_copy(L);		//复制一份字典
		int len = L[0].length();		//单词的长度
		int correct = 0;				//记录匹配了几个单词
		const char *src = S.c_str();
		for(int i=0; *src && strlen(src)>=len*L.size(); src++, i++) {
			const char *src_copy = src;
			bool flag = false;
			for(int k=0; k<result.size(); k++) {
				if(result[k] == i) {
					flag = true;
					break;
				}
			}
			if(flag)
				continue;
			//i用于记录位置
			vector<string>::iterator iter;
			for(iter=L_copy.begin(); iter!=L_copy.end();) {
				const char *pat = (*iter).c_str();
				if(!strncmp(src, pat, len)) {
					//如果找到了其中一个单词，则将其删除，src += len，j = 0，重新开始本次循环
					L_copy.erase(iter);
					src += len;
					iter = L_copy.begin();
					correct++;
					continue;			//重头开始，跳过iter++
				}
				iter++;
			}
			if(correct==L.size()) {
				//如果最后L_copy空了，说明找到了匹配的位置
				result.push_back(i);
				L_copy = L;
				int j=0;
				while(!strncmp(src+j*len, src_copy+j*len, len)) {
					//找到完全匹配的，说明当前位置跳过len个位置开始的位置已经有n-1个匹配的单词，看下一个单词是否和第一个单词一样，是的话说明也能匹配
					//例子：aobocoao
					j++;
					result.push_back(i+j*len);
				}
			}
			src -= correct*len;		//找到匹配的之后，src必须回溯到上一个位置的下一个字符位置
			correct = 0;
			L_copy = L;
		}
		return result;
	}
};

//维护一个字典，对源字符串中所有长度为l的子串进行检查
//维护一个窗口（即当前检查的长度为l的子串）
//如果当前单词在字典中，则移动窗口右端，即扩充窗口的长度
//否则窗口左端可以直接跳到下一个单词




//下面这种方法是维护了一个统计单词个数的词典，统计单词在当前位置起的字符串出现的个数
//如果没出现，则直接跳到下一个位置
//如果出现了，则进行计数，计数与原先的词典的个数进行比较，如果超出了则跳到下一个位置
//如果刚好出现了词典里的几个单词，则返回找到了一个位置

//该方法没有超时可能是substr()和计数所用的时间比较少，其他的遍历也都是需要的
class Solution {
public:
    vector<int> findSubstring(string S, vector<string> &L) {
        int l_size = L.size();
        
        if (l_size <= 0) {
            return vector<int>();
        }
        
        vector<int> result;
        map<string, int> word_count;
        int word_size = L[0].size();
        int i, j;
        
        for (i = 0; i < l_size; ++i) {
            ++word_count[L[i]];
        }
        
        map<string, int> counting;
        
        for (i = 0; i <= (int)S.length() - (l_size * word_size); ++i) {
            counting.clear();
            
            for (j = 0; j < l_size; ++j) {
                string word = S.substr(i + j * word_size, word_size);
               
                if (word_count.find(word) != word_count.end()) {
                    ++counting[word];
                    
                    if (counting[word] > word_count[word]) {
                        break;
                    }
                }
                else {
                    break;
                }
            }
            
            if (j == l_size) {
                result.push_back(i);
            }
        }
        
        return result;
    }
};