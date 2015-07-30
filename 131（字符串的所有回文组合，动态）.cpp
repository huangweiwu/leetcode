// 给定一个字符串，将其分割成回文子字符串，返回所有分割的组合
//	思路：
//		动态规划，s[0...i]对应的所有分割组合为一个vector<vector<string> >对象
//		当遍历到s[i]，s[i]本身是一个回文，因此在s[i-1]对应的所有组合后添加一个s[i]
//		然后再判断s[j...i]（1<=j<=i-1)是否回文，是的话，在s[j]对应的所有组合后添加s[j...i]

//	空间复杂度比较高

class Solution {
public:
	bool isPalindrome(string s, int start, int end) {
		if(start >= end)
			return true;
		while(start < end) {
			if(s[start] != s[end])
				return false;
			start++;
			end--;
		}
		return true;
	}
    vector<vector<string>> partition(string s) {
		vector<vector<string> > ret;
		ret.clear();
		if(s.length() == 0)
			return ret;
		if(s.length() == 1) {
			vector<string> tmp;
			tmp.push_back(s);
			ret.push_back(tmp);
			return ret;
		}
		vector<vector<string> > *rett = new vector<vector<string> >[s.length() + 1];
		rett[0].clear();
		vector<string> tmp;
		string tt = "";
		tt += s[0];
		tmp.push_back(tt);
		rett[1].push_back(tmp);
		for(int i=2; i<=s.length(); i++) {
			for(int j=0; j<rett[i-1].size(); j++) {
				// 在rett[i-1]中每一个元素后添加s[i-1]，然后插入rett[i]中
				vector<string> tmp = rett[i-1][j];
				tt = "";
				tt += s[i-1];
				tmp.push_back(tt);
				rett[i].push_back(tmp);
			}
			for(int k=0; k<i-1; k++) {
				if(isPalindrome(s, k, i-1)) {
					if(k == 0) {
						vector<string> tmp;
						tmp.push_back(s.substr(k, i-k));
						rett[i].push_back(tmp);
					}
					// 如果是回文，则在rett[k]中每个元素后添加s[k...i]，然后插入rett[i]中
					for(int j=0; j<rett[k].size(); j++) {
						vector<string> tmp = rett[k][j];
						tmp.push_back(s.substr(k, i-k));
						rett[i].push_back(tmp);
					}
				}
			}
		}
		return rett[s.length()];
    }
};

// 下面这个是回溯法，不理解。。
class Solution {
public:
    void palPart (vector<vector<string>> &ans,vector<string> &temp,string s,int j){
        if(s.size()==0)
            return;
        //特殊输入
        if(j>s.size()-1){
        ans.push_back(temp);
        return;
        }
        //边界条件，很重要
        int m,n,l;

        for(m=s.size()-1;m>=j;m--){
            l=j;
            n=m;

            while(l<n&&s[l]==s[n]){

                l++;
                n--;

            }//判断s(j,m)是不是回文
            if(l>=n){

                temp.push_back(s.substr(j,m-j+1));//子串入栈

                palPart(ans,temp,s,m+1);//遍历

                temp.pop_back();//遍历完毕，子串出栈
            }
        }
    }

    vector<vector<string>> partition(string s) {
    vector<vector<string> >  ans;
    vector<string> temp;
    palPart (ans,temp,s,0);
    return ans;
    }
};