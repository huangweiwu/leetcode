

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 在搜索二叉树中找到两个结点的最低公共祖先
//	思路：
//		判断p和q的值与root的关系
//		若有一个小于一个大于root的值，则返回root
//		若两个都大于root，则root = root->right；若两个都小于，则root = root->left

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		if(p->val > root->val && q->val > root->val)
			return lowestCommonAncestor(root->right, p, q);
		if(p->val < root->val && q->val < root->val)
			return lowestCommonAncestor(root->left, p, q);
		return root;
    }
};