/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int diameter = 0;
int reculsiveDepth(TreeNode* cur)
{
	int left_depth = 0;
	int right_depth = 0;
	if (cur->left)
		left_depth = reculsiveDepth(cur->left);
	if (cur->right)
		right_depth = reculsiveDepth(cur->right);
	diameter = max(diameter, (left_depth + right_depth));
	int node_depth = max(left_depth, right_depth);
	return node_depth + 1;
}
int diameterOfBinaryTree(TreeNode* root) 
{
	if (!root)
		return 0;
	TreeNode* cur = root;
	reculsiveDepth(cur);
    return diameter;
}
};
