// 给定一组数，求其中的一个峰值点的位置
//	思路：二分检索
//		如果nums[mid] > nums[mid-1] && nums[mid] > nums[mid+1]，则返回mid
//		如果nums[mid] < nums[mid-1]，则end = mid - 1
//		如果nums[mid] > nums[mid+1]，则start = mid + 1
//		因为存在较大数的半区间内肯定存在峰值点

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 0;
		int end = nums.size() - 1;
		int mid;
		while(start < end - 1) {
			mid = (start + end) >> 1;
			if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
				return mid;
			if(nums[mid] < nums[mid - 1])
				end = mid - 1;
			if(nums[mid] < nums[mid + 1])
				start = mid + 1;
		}
		return nums[start] > nums[end] ? start : end;
    }
};

int main() {
	Solution so;
	
	ListNode* head = new ListNode(1);
	head->next = new ListNode(2);
	head->next->next = new ListNode(3);
	head->next->next->next = new ListNode(4);
	head->next->next->next->next = new ListNode(5);
	head->next->next->next->next->next = new ListNode(6);

	ListNode* headA = new ListNode(3);
	ListNode* headB = new ListNode(2);
	headB->next = headA;
	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {1, 2, 3, 4, 5};
	vector<int> v(a, a+5);
	cout << so.findPeakElement(v);
	
	system("pause");
	return 0;
}