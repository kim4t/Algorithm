/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans;
    TreeNode* p;
    TreeNode* q;
bool hasValue(TreeNode* cur)
{
	int found = 0;
	int left_found = 0;
	int right_found = 0;

	if (cur == p|| cur == q)
		found = 1;

	if (cur->left)
		left_found = hasValue(cur->left);

	if (cur->right)
		right_found = hasValue(cur->right);

	int found_count = found + left_found + right_found;

	if (found_count == 2)
		ans = cur;

	return found_count > 0 ? true : false;
	
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* pp, TreeNode* qq) 
{
	TreeNode* cur = root;
	p = pp;
	q = qq;
	hasValue(cur);
	return ans;
}
};
