//给定一组字符串数组，返回所有变位词组
//遍历字符串数组，对于每个字符串，对其进行排序，然后判断是否出现过一样的字符串，是的话则将其保存
//可以将前面出现过的字符串用一个map结构smp保存起来，保存字符串本身及其下标
//需要注意的问题是：
//对于变位词组中第一个出现的字符串str
//先将smp[str]置为其下标，下次找到和它一样的则将其保存，并将smp[str]改为-1即可

class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> result;
		map<string, int> smp;

		for(int i=0; i<strs.size(); i++) {
			string tmpstr = strs[i];
			sort(tmpstr.begin(), tmpstr.end());
			if(smp.find(tmpstr) == smp.end())
				//没找到变位词，将其保存起来
				smp[tmpstr] = i;
			else {
				if(smp[tmpstr] == -1)
					//第一个变位词已经保存过
					result.push_back(strs[i]);
				else {
					//第一个变位词没保存
					result.push_back(strs[smp[tmpstr]]);
					smp[tmpstr] = -1;
					result.push_back(strs[i]);
				}
			}
		}
		return result;
    }
};