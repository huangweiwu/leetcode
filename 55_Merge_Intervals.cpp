//给定一组区间，将有重合的区间都合并起来
//思路：
//1） 先将这些区间按照左坐标进行排序
//2） 从第二个区间开始遍历，�查看左坐标是否比小于等于上一个区间的右坐标，是的话则合并




struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

int comp(Interval a, Interval b) {
	return a.start < b.start;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
		if(intervals.size()==0 || intervals.size()==1)
			return intervals;
		vector<Interval> result;
		sort(intervals.begin(), intervals.end(), comp);
		result.push_back(intervals[0]);
		for(int i=0, j=1; j<intervals.size(); j++) {
			if(intervals[j].start <= result[i].end) {
				result[i].end = intervals[j].end > result[i].end ? intervals[j].end : result[i].end;
			}
			else {
				result.push_back(intervals[j]);
				i++;
			}
		}
		return result;
    }
};