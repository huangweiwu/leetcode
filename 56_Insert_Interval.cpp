//给定一组没有交集的区间，再给定一个区间，将重合的进行合并
//思路：
//找到和给定区间重合的区间范围，对其进行合并即可
//要注意的情况还蛮多的
//1） 没有交集的时候，新区间的位置，是在最前面、中间还是最后面
//2） 有交集的时候，是交在最前面还是最后面

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        vector<Interval> result;
		if(intervals.size() == 0) {
			result.push_back(newInterval);
			return result;
		}
		bool flag_left = false;
		bool flag_right = false;
		bool flag = false;
		int left;
		int right = intervals.size() - 1;
		int i = 0;
		for(; i<intervals.size(); i++) {
			if(!flag_left) {
				//第一个交叉的区间还没找到
				if(newInterval.start<=intervals[i].end && newInterval.end>=intervals[i].start) {
					flag = true;
					flag_left = true;
					left = i;
					right = i;
					if(i == intervals.size()-1)
						//只有最后一个区间和新区间有交集
						break;
				}
			}
			if(!flag_right) {
				//最后一个交叉的区间还没找到
				if(i == intervals.size() - 1) {
					if(newInterval.start<=intervals[i].end && newInterval.end>=intervals[i].start) {
						flag_right = true;
						right = i;
						break;
					}
				}
				if(newInterval.start<=intervals[i].end && newInterval.end>=intervals[i].start && newInterval.end < intervals[i+1].start) {
					//和前一个区间有交集，但和后一个区间没有交集，说明找到了最后一个
					flag_right = true;
					right = i;
					break;
				}
			}
			if(!flag_left && !flag_right && newInterval.end < intervals[i].start)
				break;
			if(!flag_left && !flag_right) {
				//当前还没找到任何重复的
				result.push_back(intervals[i]);
			}
		}
		if(flag) {
			//如果找到了重合的区间
			struct Interval tmp(intervals[left].start < newInterval.start ? intervals[left].start : newInterval.start, newInterval.end < intervals[right].end ? intervals[right].end : newInterval.end);
			//tmp.start = intervals[left].start < newInterval.start ? intervals[left].start : newInterval.start;
			//tmp.end = newInterval.end < intervals[right].end ? intervals[right].end : newInterval.end;
			result.push_back(tmp);
			if(i == intervals.size() - 1)
				return result;
			i++;
		}
		else {
			result.push_back(newInterval);
		}
		while(i < intervals.size()) {
			result.push_back(intervals[i]);
			i++;
		}
		return result;
    }
};