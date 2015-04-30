//给定一组数字
//返回所有可能的组合
//思路：
//递归法
//在num中取出第一个数字，对剩余的数字做一个全排列得到结果temp_ret
//然后递归将num的第一个数字插入到返回的所有结果temp_ret的所有位置

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
          
        return ret;
    }
};

//建立一棵树，比如说
//        1234
//1234    2134   3214    4231     //就是swap(1,1)  swap(1,2) swap(1,3) swap(1,4)
//    |          
//234  324  432
//   |
//34 43
//然后就用DFS遍历一下，叶子节点就是我们想要的啦
class Solution {  
      
    vector<vector<int> > ret;  
    int N;  
      
public:  
    void perm(vector<int> &num, int i){  
        if(i == N){  
            ret.push_back(num);  
        }  
          
        for(int j = i; j < N; j++){  
            swap(num[i], num[j]);  
            perm(num, i + 1);  
            swap(num[j], num[i]);  
        }  
    }  
  
  
    vector<vector<int> > permute(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        N = num.size();  
        ret.clear();  
          
        perm(num, 0);  
          
        return ret;  
          
    }  
};


//stl的algorithm里面有next permutation的算法，swap+reverse
class Solution {  
public:  
     void nextPermutation(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
          
        //5,4,7,5,3,2  
        //    |     |  
        //    i     j  
        //5,5,7,4,3,2  
        //5,5,2,3,4,7  
        int i = num.size()-1;  
        while(i > 0 && num[i-1] >= num[i] ){
            i--;
        }
        int j = i;  
          
        while(j < num.size() && num[j] > num[i-1]) j++;  
          
        if(i == 0){  
            reverse(num.begin(), num.end());  
        }else{  
            swap(num[i-1], num[j-1]);  
            reverse(num.begin() + i, num.end());  
        }
    }  
      
    int factorial(int n){  
        return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;  
    }  
  
  
    vector<vector<int> > permute(vector<int> &num) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int N = num.size();  
        vector<vector<int> > ret;  
          
        ret.push_back(num);  
          
        for(int i = 1; i < factorial(N); i++){  
            nextPermutation(num);  
            ret.push_back(num);  
        }  
          
        return ret;
    }
};