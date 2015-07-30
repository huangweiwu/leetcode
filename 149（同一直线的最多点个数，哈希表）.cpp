// 给定一组二维点，求在同一直线上的最多点个数
//	思路：遍历所有点，再遍历其后所有点，统计与当前点的斜率的个数；斜率相同的在同一直线上
//	注意：x坐标相同的没有斜率，要单独统计；坐标点重复的也是要单独统计

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};
class Solution {
public:
    int maxPoints(vector<Point>& points) {
		if(points.size() <= 2)
			return points.size();
		int ret = 0;
		int duplicate, vertex;
		int local;							// 统计当前轮的最多个数
		unordered_map<double, int> m;
		for(int i=0; i<points.size(); i++) {
			duplicate = 0;
			vertex = 0;
			local = 0;
			m.clear();
			for(int j=i+1; j<points.size(); j++) {
				if(points[j].x == points[i].x) {
					if(points[j].y == points[i].y)
						duplicate++;
					else
						vertex++;
				}
				double slope = (points[j].y - points[i].y) * 1.0 / (points[j].x - points[i].x);
				m[slope]++;
				local = max(local, m[slope]);
			}
			ret = max(ret, max(local, vertex) + duplicate + 1);
		}
		return ret;
    }
};