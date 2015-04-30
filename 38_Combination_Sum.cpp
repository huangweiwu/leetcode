//给定一组数C和一个数T，在C中找出所有的组合，和为T
//条件：
//1） 所有的数都是正数
//2） C是以非降序排序的
//思路：
//维护一个栈，并将第一个元素入栈，当前栈中元素和为sum，初始化sum=candidates[0]，判断sum+candidates[pos[i]]
//记录一个变量i，记录当前数组pos的位置，i=0；维护一个数组pos，记录当前栈中每个位置遍历到了candidates的哪个位置，初始化pos[]数组都为0
//1） 如果和小于target，则将candidates[pos[i]]入栈，i++，sum += candidates[pos[i]];继续判断
//2） 如果和等于target，则将栈中的所有元素作为一个结果返回；pos[i]++;
//3） 如果和大于target，则将栈顶元素出栈，i--，sum -= candidates[pos[i]]，i--，pos[i]++，
//
//中间需要考虑挺多细节问题，注意各种终止条件
//当栈的元素个数为1，且和大于target时，跳出循环

class Solution {
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
		sort(candidates.begin(), candidates.end());
        vector<vector<int> > result;
		int i = 0;
		int *pos = new int[100];
		memset(pos, 0, sizeof(int)*100);
		int sum = 0;
		vector<int> temp;
		temp.clear();
		while(1) {
			if(sum+candidates[pos[i]] < target) {
				sum += candidates[pos[i]];
				temp.push_back(candidates[pos[i]]);
				i++;
				pos[i] = pos[i-1];
				continue;
			}
			if(sum+candidates[pos[i]] == target) {
				temp.push_back(candidates[pos[i]]);
				result.push_back(temp);
				temp.pop_back();
				//往前退一格，因为后面的数都比当前格大，加起来和也必然比sum大
				if(pos[0]==candidates.size()-1 || i==0)
					//栈里只剩下最后一个元素或者所有元素都已遍历过
					break;
				i--;
				sum -= candidates[pos[i]];
				temp.pop_back();
				while(pos[i] == candidates.size()-1) {
					//往前退格不能直接pos[i]++，因为有可能前一格已经到达了最后一个元素
					i--;
					sum -= candidates[pos[i]];
					temp.pop_back();
				}
				pos[i]++;
				continue;
			}
			if(sum+candidates[pos[i]] > target) {
				if(pos[0]==candidates.size()-1 || temp.size()==0)
					//栈里只剩下最后一个元素或者遍历到比target大的元素
					break;
				i--;
				sum -= candidates[pos[i]];
				temp.pop_back();
				while(pos[i] == candidates.size()-1) {
					i--;
					sum -= candidates[pos[i]];
					temp.pop_back();
				}
				pos[i]++;
			}
		}
		return result;
    }
};

//思路很赞，用DFS来做
//终止条件：
//1） target < 0
//2） dep == maxDep
//在第二种情况下，若target==0，则得到了答案
//为何一个数组a，用来保存每个位置的元素使用了多少次

class Solution {
private:
    vector<vector<int> > ret;
    vector<int> a;
public:
    void solve(int dep, int maxDep, int target, vector<int> &cand)
    {
        if (target < 0)
            return;
            
        if (dep == maxDep)
        {
            if (target == 0)
            {
                vector<int> res;
                for(int i = 0; i < maxDep; i++)
                    for(int j = 0; j < a[i]; j++)
                        res.push_back(cand[i]);
                ret.push_back(res);
            }
            return;
        }
        
        for(int i = 0; i <= target / cand[dep]; i++)
			//关键部分代码，每个位置的元素能使用的次数决定于target剩余的部分与它本身值的商
        {
            a[dep] = i;
            solve(dep + 1, maxDep, target - cand[dep] * i, cand);
        }
    }
    
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(candidates.begin(), candidates.end());
        
        a.resize(candidates.size());
        ret.clear();
        if (candidates.size() == 0)
            return ret;
            
        solve(0, candidates.size(), target, candidates);
        
        return ret;
    }
};