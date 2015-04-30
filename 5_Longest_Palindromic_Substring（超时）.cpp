//找一个字符串中的最长回文
//思路：先将字符串s反转并保存在另外一个字符串s_rev，从s_rev中查找s的最长子串
//要注意的就是内外循环中局部变量的使用、恢复等
//如本程序中的j在内循环过后需要恢复为0，而i在内循环中不能使用，故定义了局部变量temp_i来替代它，这样在每次内部循环开始时也必须将temp_i赋值为i，temp_j保存当前在匹配的源字符串的起始位置
//本方法时间复杂度比较高，解决方法
//1） 在内外部循环中都加入剪枝条件，即当目前得到的长度超过了剩下要遍历的长度，则跳出循环
//2） 使用KMP模式匹配算法，关键是next数组的求解，以及怎么运用到本题中来，s_rev每进一步都得重新计算next_val
//3） 如果找到长度大于1的匹配串，则源字符串中的位置i可以直接跳过该匹配字符串


//下面这种方法采用了KMP匹配，速度比较慢
class Solution {
public:
	string strRev(string s) {
		string result = "";
		int i=0;
		while(i<s.length()) {
			result += s[s.length()-i-1];
			i++;
		}
		return result;
	}
	void get_nextval(string ptrn, int plen, int* nextval)    
	{    
		int i = 0;     
		nextval[i] = -1;    
		int j = -1;    
		while( i < plen-1 )    
		{    
			if( j == -1 || ptrn[i] == ptrn[j] )   //循环的if部分    
			{    
				++i;    
				++j;    
				//修正的地方就发生下面这4行    
				if( ptrn[i] != ptrn[j] ) //++i，++j之后，再次判断ptrn[i]与ptrn[j]的关系    
					nextval[i] = j;      //之前的错误解法就在于整个判断只有这一句。    
				else    
					nextval[i] = nextval[j];    
			}    
			else                                 //循环的else部分    
				j = nextval[j];    
		}    
	}
    string longestPalindrome(string s) {
        string s_rev = strRev(s);
		int i=0;
		int j=0;
		int* nextval = new int[1002];
		string result = "";
		string temp_res = "";
		int length = 0;
		int temp_length = 0;
		while(i<s_rev.length()) {
			//在内循环用temp_str替代s_rev进行匹配
			string temp_str = s_rev.substr(i, s_rev.length()-i);
			get_nextval(temp_str, temp_str.length(), nextval);
			//从s_rev找s的最长连续子串
			int temp_i = 0;
			while(j<s.length()) {
				if(temp_i==-1 || temp_str[temp_i] == s[j]) {
					//匹配成功
					if(temp_i!=-1 && temp_str[temp_i] == s[j]) {
						temp_length++;
						temp_res += s[j];
					}
					temp_i++;
					j++;
				}
				else {
					//匹配失败
					if(temp_length > length) {
						result = temp_res;
						length = temp_length;
					}
					temp_i = nextval[temp_i];
					temp_length = 0;
					temp_res = "";
				}
				if(length >= s.length()-j)
					break;
			}
			i++;
			if(temp_length > length) {
				result = temp_res;
				length = temp_length;
			}
			temp_length = 0;
			temp_res = "";
			if(length >= s_rev.length()-i)
				break;
			j=0;
		}
		return result;
    }
};


//下面这种方法直接进行匹配
class Solution {
public:
	string strRev(string s) {
		string result = "";
		int i=0;
		while(i<s.length()) {
			result += s[s.length()-i-1];
			i++;
		}
		return result;
	}
    string longestPalindrome(string s) {
        string s_rev = strRev(s);
		int i=0;
		int j=0;
		string result = "";
		string temp_res = "";
		int length = 0;
		int temp_length = 0;
		while(i<s_rev.length()) {
			//从s_rev找s的最长连续子串
			int temp_i = i;
			int temp_j = j;
			while(j<s.length()) {
				if(s_rev[temp_i] == s[j]) {
					temp_i++;
					temp_length++;
					temp_res += s[j];
				}
				else {
					temp_i = i;
					temp_j = j;
					if(temp_length > length) {
						result = temp_res;
						length = temp_length;
					}
					temp_length = 0;
					temp_res = "";
				}
				//匹配到了字符串的结尾
				if(j+1 == s.length()) {
					if(temp_length > length) {
						result = temp_res;
						length = temp_length;
					}
					temp_length = 0;
					temp_res = "";
				}
				j++;
				if(length >= s.length()-temp_j)
					break;
			}
			if(length >= s_rev.length()-i)
				break;
			i++;
			j=0;
		}
		return result;
    }
};


//动态规划算法求解，Memory Limit Exceeded
//如果s[i] == s[j] 那么是否是回文决定于 dp[i+1][ j - 1]
//当 s[i] != s[j] 的时候， dp[i][j] 直接就是 false。
//动态规划的进行是按照字符串的长度从1 到 n推进的。
class Solution {
public:
    string longestPalindrome(string s) {
		int len = s.length();
        bool** dp = new bool*[len];
		for(int i=0; i<len; i++) {
			dp[i] = new bool[len];
		}

		int ss = 0;				//最长子串的开始位置
		int max = 1;			//最长子串的长度
		for(int i=0; i<len; i++) {
			for(int j=0; j<len; j++) {
				if(i >= j)
					//当i == j 的时候，只有一个字符的字符串; 当 i > j 认为是空串，也是回文
					dp[i][j] = true;
				else
					dp[i][j] = false;
			}
		}
		for(int j=1; j<len; j++) {
			for(int i=0; i<j; i++) {
				if(s[i] == s[j]) {
					dp[i][j] = dp[i+1][j-1];
					if(dp[i][j] && j-i+1>max) {
						max = j-i+1;
						ss = i;
					}
				}
				else
					dp[i][j] = false;
			}
		}
		return s.substr(ss, max);
	}
};



//Manacher’s Algorithm的算法，时间复杂度为O(n)
//思路很赞，http://blog.csdn.net/hopeztm/article/details/7932245
string preProcess(string s) {  
  int n = s.length();  
  if (n == 0) return "^$";  
  string ret = "^";  
  for (int i = 0; i < n; i++)  
    ret += "#" + s.substr(i, 1);  
   
  ret += "#$";  
  return ret;  
}  
   
string longestPalindrome(string s) {  
  string T = preProcess(s);  
  int n = T.length();  
  int *P = new int[n];  
  int C = 0, R = 0;  
  for (int i = 1; i < n-1; i++) {  
    int i_mirror = 2*C-i; // equals to i' = C - (i-C)  
   
    P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;  
   
    // Attempt to expand palindrome centered at i  
    while (T[i + 1 + P[i]] == T[i - 1 - P[i]])  
      P[i]++;  
   
    // If palindrome centered at i expand past R,  
    // adjust center based on expanded palindrome.  
    if (i + P[i] > R) {  
      C = i;  
      R = i + P[i];  
    }  
  }  
   
  // Find the maximum element in P.  
  int maxLen = 0;  
  int centerIndex = 0;  
  for (int i = 1; i < n-1; i++) {  
    if (P[i] > maxLen) {  
      maxLen = P[i];  
      centerIndex = i;  
    }  
  }  
  delete[] P;  
   
  return s.substr((centerIndex - 1 - maxLen)/2, maxLen);  
}