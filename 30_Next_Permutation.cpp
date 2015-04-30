//实现next_permutation，即下一个排列组合，在词典学意义上的下一个组合
//如果没有下一个的话，则返回最小的那个，这就相当于一个自循环
//不分配多余的空间
//思路：
//1） 找到最后一个比右边元素小的元素，将其与右边元素中比它本身大的最小的数进行交换
//交换位置后对后面的元素进行从小到大排序

class Solution {
public:
    void nextPermutation(vector<int> &num) {
		int len = num.size();
		vector<int>::iterator iter = num.end();
		iter--;		//将iter移到与i的后一个位置，如果找到符合条件的，则从iter位置开始排序
		for(int i=len-2; i>=0; i--, iter--) {
			if(num[i] >= num[i+1])
				continue;
			//右边元素比它大，则找右边比它大的元素中最小的那个
			int max_min = num[i+1];
			int pos = i + 1;
			for(int j=i+2; j<len; j++) {
				if(num[j]>num[i] && num[j]<max_min) {
					max_min = num[j];
					pos = j;
				}
			}
			//将两个元素交换位置
			int temp = num[i];
			num[i] = num[pos];
			num[pos] = temp;
			//将位置i后的元素进行排序
			sort(iter, num.end());
			return;
		}
		//如果跳出了循环，说明不存在下一个，则回到最小的那个
		sort(num.begin(), num.end());
		return;
    }
};