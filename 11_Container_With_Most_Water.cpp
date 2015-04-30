//有一个n元数组，a1,a2,...,an，分别表示坐标(i, ai)，这些点分别与(i, 0)连成n条线，求其中的两条线，使得其与x轴组成的容器包含最多的水
//思路：包含最多的水，即是体积最大，用穷举法，两趟遍历，可以求得体积最大的一个
//剪枝法可以将一些情况去掉，如与a1结对的，离ai越近但是高度也越低，则不用计算其体积可以直接跳过
//即在遍历节点ai的配对节点的容器体积时，从离得最远的点开始算起

//假设我们找到能取最大容积的纵线为 i , j ；j的后边不会有比它还高的线；i的左边也不会有比它高的线
//如果我们目前得到的候选： 设为 x, y两条线（x< y)，那么能够得到比它更大容积的新的两条边必然在  [x,y]区间内并且 ax' > =ax , ay'>= ay;

//问题：剪枝法无法满足时间复杂度要求，要求从两边同时收缩，在收缩区间的时候优先从  x, y中较小的边开始收缩；

/*class Solution {
	int calculate_volume(int i, int ai, int j, int aj) {
		//根据两个点计算体积，保证传进来的参数i<j
		int height1 = ai>aj?aj:ai;
		int r = j-i;
		int result = 0;
		result += r*height1;
		return result;
	}

public:
    int maxArea(vector<int> &height) {
        int result = 0;
		int temp_max_height = 0;				//保存当前遍历节点中右边的节点高度最高的节点，用于剪枝
		int temp_result = 0;
		int cal_height = 0;
		for(int i=0; i<height.size()-1; i++) {
			temp_result = calculate_volume(i, height[i], height.size()-1, height[height.size()-1]);
			result = temp_result>result?temp_result:result;
			temp_max_height = height[height.size()-1];
			for(int j=height.size()-2; j>i; j--) {
				if(height[j] < temp_max_height)
					//剪枝，如果当前遍历节点比右边节点的高度低，则直接跳过，不需要进行计算
					continue;
				temp_result = calculate_volume(i, height[i], j, height[j]);
				result = temp_result>result?temp_result:result;
				temp_max_height = height[j];
			}
		}
		return result;
    }
};*/
class Solution {  
public:  
    int maxArea(vector<int> &h) {  
        // Start typing your C/C++ solution below  
        // DO NOT write int main() function  
        int res=0;  
        int n = h.size();  
        int l=0,r=n-1;  
        while(l<r)  
        {  
            res=max(res,min(h[l],h[r])*(r-l));  
            if (h[l]<h[r])  
            {  
                int k=l;  
                while(k<r&&h[k]<=h[l])  
                    k++;  
                l=k;  
                }  
            else  
            {  
                int k=r;  
                while(k>l&&h[k]<=h[r])  
                    k--;  
                r=k;  
             }  
        }  
        return res;  
    }  
}; 