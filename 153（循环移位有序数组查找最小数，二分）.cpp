class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
		int end = nums.size() - 1;
		int mid = (start + end) >> 1;
		while(start < end - 1) {
			mid = (start + end) >> 1;
			if(nums[mid] > nums[start] && nums[mid] < nums[end])
			// 如果是nums[0]/nums[mid]/nums[end]是有序的，说明第一个元素为最小的
				return nums[start];
			if(nums[mid] < nums[mid-1] && nums[mid] < nums[mid+1])
				return nums[mid];
			if(nums[mid] > nums[start] && nums[mid] > nums[end])
				start = mid + 1;
			if(nums[mid] < nums[start] && nums[mid] < nums[end])
				end = mid - 1;
		}
		return min(nums[start], nums[end]);
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

	

	TreeNode* head1 = new TreeNode(1);
	//head1->left = new TreeNode(2);
	head1->left = new TreeNode(2);
	head1->left->left = new TreeNode(2);
	
	TreeLinkNode* root = new TreeLinkNode(1);
	root->left = new TreeLinkNode(2);
	root->right = new TreeLinkNode(3);
	int a[6] = {4, 5, 6, 1, 2, 3};
	vector<int> v(a, a+6);
	cout << so.findMin(v);
	
	system("pause");
	return 0;
}