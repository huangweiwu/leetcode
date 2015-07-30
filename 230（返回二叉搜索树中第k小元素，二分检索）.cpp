

// 从二叉搜索树中返回第k小元素
//	思路1：二分检索，查找当前结点的左子树的结点个数，时间复杂度为O(lg h)，h为树的高度
//		如果结点个数为k-1，则返回当前结点值
//		如果结点个数小于k-1，则结果在右子树中
//		如果结点个数大于k-1，则结果在左子树中

class Solution {
public:
	int kthSmallest(TreeNode* root, int k) {
		if(root == nullptr)
			return 0;
		int count = countNodes(root->left);
		if(count == k - 1)
			return root->val;
		else if(count < k - 1)
			return kthSmallest(root->right, k - count - 1);
		else
			return kthSmallest(root->left, k);			
	}
	int countNodes(TreeNode* root) {
		if(root == nullptr)
			return 0;
		return 1 + countNodes(root->left) + countNodes(root->right);
	}
};

//	思路2：以中序遍历来查找，先从左子树查找
//		如果左子树查找刚好将k减少为0，则返回左子树得到的结果
//		如果左子树查找刚好将k减少为1，则返回当前结点值
//		否则从右子树中查找

class Solution {
public:
        int kthSmallest(TreeNode* root, int& k) {
            if (root) {
                int x = kthSmallest(root->left, k);
                return !k ? x : !--k ? root->val : kthSmallest(root->right, k);
            }
        }
};