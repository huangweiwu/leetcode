#include<iostream>
#include<string>
#include<vector>
using namespace std;

// 翻转一棵二叉树
// 思路：递归翻转左右子树

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
			return NULL;

		else {
			if(root->left != NULL)
				invertTree(root->left);
			if(root->right != NULL)
				invertTree(root->right);
			TreeNode* temp = root->left;
			root->left = root->right;
			root->right = temp;
		}
    }
};

int main() {
	Solution so;
	TreeNode* root = new TreeNode(4);
	root->left = new TreeNode(2);
	root->left->left = new TreeNode(1);
	root->left->right = new TreeNode(3);

	root->right = new TreeNode(7);
	root->right->left = new TreeNode(6);
	root->right->right = new TreeNode(9);

	so.invertTree(root);

	system("pause");
	return 0;
}