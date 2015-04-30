//给定一组整型数组，找出所有的加起来和为0的三元组
//思路，先排序，然后将其分成小于等于零和大于零两组
//遍历小于等于零的二元组，并从大于零组中二分查找该二元组和的相反数
//此外，在小于等于零的数组中，相同的负数最多只能出现两次，且对于相同的数，遍历其二元组只需要遍历一次

//出现了"Output Limit Exceeded"的错误


#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

./*class Solution {*/
public:
	bool binary_chop(int a, vector<int>& vec) {
		//从排序号的数组vec中二分查找a，找到则返回1，找不到则返回0
		int begin = 0;
		int end = vec.size() - 1;
		//bool result = binary_chop_help(a, vec, begin, end);
		while(begin < end-1) {
			int mid = (begin+end) / 2;
			if(vec[mid] == a)
				return true;
			else if(vec[mid] > a)
				end = mid;
			else
				begin = mid;
		}
		if(vec[begin]==a || vec[end]==a)
			return true;
		return false;
	}
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		result.clear();
		vector<int> temp;
		if(num.size() < 3)
			//如果元素个数小于3，则不存在对应的三元组
			return result;
		sort(num.begin(), num.end());
		int zero_count=0;
		for(int i=0; i<num.size(); i++) {
			if(num[i] == 0) {
				zero_count++;
				if(zero_count > 2) {
					temp.push_back(0);
					temp.push_back(0);
					temp.push_back(0);
					result.push_back(temp);
					break;
				}
			}
		}
		if(num[0]>=0 || num[num.size()-1] <=0) 
			//如果仅有正数或仅有负数，则不存在对应的三元组
			return result;
		vector<int> negative_zero;
		vector<int> positive;
		int temp_count = 1;					//存储当前访问的数值的个数
		negative_zero.push_back(num[0]);
		for(int i=1; i<num.size(); i++) {
			//将数组分为大于等于零和小于零的两个数组
			if(num[i]==num[i-1])
				temp_count++;
			else
				temp_count = 1;
			if(temp_count > 2)
				//跳过重复三次的数
				continue;
			if(num[i] <= 0)
				negative_zero.push_back(num[i]);
			else
				positive.push_back(num[i]);
		}
		
		bool is_traverse = false;
		for(int i=0; i<negative_zero.size()-1; i++) {
			if(is_traverse) {
				is_traverse = false;
				continue;
			}
			if(negative_zero[i+1] == negative_zero[i])
				is_traverse = true;
			for(int j=i+1; j<negative_zero.size(); j++) {
				temp.clear();
				int oppo = -(negative_zero[i]+negative_zero[j]);
				if(binary_chop(oppo, positive)) {
					temp.push_back(negative_zero[i]);
					temp.push_back(negative_zero[j]);
					temp.push_back(oppo);
					result.push_back(temp);
				}
			}
		}
		for(int i=0; i<positive.size()-1; i++) {
			if(i>0 && negative_zero[i] == negative_zero[i-1])
			//之前已经遍历过了相同数值的节点则跳过
				continue;
			for(int j=i+1; j<positive.size(); j++) {
				temp.clear();
				int oppo = -(positive[i]+positive[j]);
				if(binary_chop(oppo, negative_zero)) {
					temp.push_back(positive[i]);
					temp.push_back(positive[j]);
					temp.push_back(oppo);
					result.push_back(temp);
				}
			}
		}
		return result;
    }
};


//另一种思路，也是先排序，然后遍历0<=i<len-1;
//j=i+1;k=last，有三种情况
//1） num[i] + num[j] > -num[k]，则k--
//2） num[i] + num[j] < -num[k], 则j++
//3） num[i] + num[j] = -num[k], 则记录，并k--,j++
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
		vector<vector<int> > result;
		result.clear();
		int len = num.size();
		if(len>=0 && len<=2)
			return result;
		vector<int> temp;
		temp.clear();
		sort(num.begin(), num.end());
		
		for(int i=0; i< num.size()-2; i++) {
			if(i>0 && num[i]==num[i-1])
			//跳过相同的数的遍历
				continue;
			int j = i + 1;
			int k = num.size() - 1;
			while(j < k) {
				int twoSum = num[i] + num[j];
				if(twoSum + num[k] > 0)
					k--;
				else if(twoSum + num[k] < 0)
					j++;
				else {
					temp.push_back(num[i]);
					temp.push_back(num[j]);
					temp.push_back(num[k]);
					result.push_back(temp);
					temp.clear();
					k--;
					j++;
					while(num[j]==num[j-1] && j<k) 
						j++;
					while(num[k]==num[k+1] && j<k)
						k--;
				}
			}
		}
		return result;
    }
};

int main()
{
	Solution so;
	int a[12] = {-3,-1,-3,-1,0,0,0,0,2,4,2,4};
	vector<int> num(a, a+12);
	vector<vector<int> > result;
	result = so.threeSum(num);

	system("pause");
	return 0;
}