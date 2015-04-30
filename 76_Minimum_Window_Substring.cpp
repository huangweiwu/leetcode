//给定一个源字符串S和一个目标字符串T，从S中找到包含T所有字符的最短子字符串
//思路：
//正向遍历，找到第一个包含目标字符串T的最短子串result
//继续遍历，遇到目标字符串中的字符，则反向遍历其包含T的最短子串，比原result长度短则更新
//结果：Time Limit Excceeded
class Solution {
public:
    string minWindow(string S, string T) {
        map<char, bool> t_map;
		for(int i=0; i<T.length(); i++)
			t_map[T[i]] = true;
		map<char, bool> tmp_map = t_map;			//用于表示目前找到几个字符
		string result = "";
		int pos = 0;
		while(pos < S.length()) {
			if(tmp_map[S[pos]])
				tmp_map.erase(S[pos]);
			else
				tmp_map.erase(S[pos]);
			pos++;
			if(tmp_map.size() == 0) {
				//找到第一个包含字符串T的子串
				break;
			}
		}
		if(pos == S.length())
			//说明无法找到子串，返回空字符串
				return result;
		//反向找到第一个最短子串
		tmp_map = t_map;
		int rever = pos - 1;
		while(rever >= 0) {
			result += S[rever];
			if(tmp_map[S[rever]])
				tmp_map.erase(S[rever]);
			else
				tmp_map.erase(S[rever]);
			if(tmp_map.size() == 0) {
				break;
			}
			rever--;
		}
		reverse(result.begin(), result.end());
		if(result.length() == T.length())
			return result;
		while(pos < S.length()) {
			string tmp_result = "";
			tmp_map = t_map;
			//正向遍历，遇到和first_char相同的字符则反向遍历并更新result和first_char
			if(tmp_map[S[pos]]) {
				tmp_result.clear();
				rever = pos;
				int count = 0;
				while(count < result.length()) {
					tmp_result += S[rever];
					if(tmp_map[S[rever]])
						tmp_map.erase(S[rever]);
					else
						tmp_map.erase(S[rever]);
					if(tmp_map.size() == 0) {
						result = tmp_result;
						reverse(result.begin(), result.end());
						if(result.length() == T.length())
								return result;
						break;
					}
					rever--;
					count++;
				}
			}
			pos++;
		}
		return result;
	}
};

//双指针思想，尾指针不断往后扫，当扫到有一个窗口包含了所有T的字符，然后再收缩头指针，直到不能再收缩为止。最后记录所有可能的情况中窗口最小的
class Solution {
public:
      string minWindow(string S, string T) {
          int count1[256];
		  int count2[256];
		  memset(count1, 0, 256*sizeof(int));
		  memset(count2, 0, 256*sizeof(int));

		  for(int i=0; i<T.size(); i++) {
			  count1[T[i]]++;
			  count2[T[i]]++;
		  }

		  int count = T.size();

		  int start = 0, end = 0, minSize = INT_MAX, minStart = start;
		  while(end < S.size()) {
			  if(count2[S[end]] > 0) {
				  count1[S[end]]--;
				  if(count1[S[end]] >= 0)
					  //当T中某个字符在当前窗口中个数已满足
						  count--;
			  }
			  if(count == 0) {
				  //已经扫到一个窗口，收缩头指针
				  while(true) {
					  if(count2[S[start]] > 0) {
						  if(count1[S[start]] < 0)
							  count1[S[start]]++;
						  else
							  //其中某个字符已经达到包含目标字符串所需要的最小个数
							  break;
					  }
					  start++;
				  }
				  if(minSize > end - start + 1) {
					  minSize = end - start + 1;
					  minStart = start;
				  }
			  }
			  end++;
		  }
		  if(minSize == INT_MAX)
			  return "";
		  string ret(S, minStart, minSize);
		  return ret;
    }
};