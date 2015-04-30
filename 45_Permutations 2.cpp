//可能包含有重复的数字
//在前面的基础上，多加一步去掉重复项即可
//结果：Time Limit Exceeded
class Solution {
public:
    vector<vector<int> > permute(vector<int> &num) {
		int N = num.size();  
        vector<vector<int> > ret;  
          
        if(N == 1){  
            ret.push_back(num);  
            return ret;  
        }  
        vector<vector<int> > post;  
          
        vector<int> cur;  
        vector<int> tmp;  
          
        cur = num;
		cur.erase(cur.begin());
		post = permute(cur);

		for(int i=0; i<post.size(); i++) {
			for(int j=0; j<=post[i].size(); j++) {
				tmp = post[i];
				tmp.insert(tmp.begin()+j, num[0]);
				ret.push_back(tmp);
			}
		}
		sort(ret.begin(), ret.end());
		for(int i=1; i<ret.size(); i++) {
			if(ret[i] == ret[i-1])
				ret.erase(ret.begin()+i);
		}
          
        return ret;
    }
};


//在上题第二个方法中，遍历到某个数，如果前面有与它相等的数，则不进行交换
class Solution {  
      
    vector<vector<int> > ret;  
    int N;  
      
public:  
	bool noswap(vector<int> &num, int i, int step) {
        int j;
        for (j = step; j < i; j++) {
            if (num[i] == num[j])
                return true;
        }
        return false;
    }
    void perm(vector<int> &num, int i){  
        if(i == N){  
            ret.push_back(num);  
        }  
          
        for(int j = i; j < N; j++){  
			if(noswap(num, j, i))
				continue;
            swap(num[i], num[j]);  
            perm(num, i + 1);  
            swap(num[j], num[i]);  
        }  
    }  
  
  
    vector<vector<int> > permuteUnique(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        N = num.size();  
        ret.clear();  
          
        perm(num, 0);  
          
        return ret;  
          
    }  
};