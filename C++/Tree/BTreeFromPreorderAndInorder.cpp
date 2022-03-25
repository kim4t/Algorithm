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
    int root = 0;
TreeNode* creatingTree(vector<int>& preorder, vector<int>& inorder,  int left, int right)
{
	if (left > right)
		return nullptr;
	
	int inorder_idx = find(inorder.begin(), inorder.end(), preorder[root]) - inorder.begin();
	root++;

	TreeNode* cur = new TreeNode(inorder[inorder_idx]);
	cur->left = creatingTree(preorder, inorder, left, inorder_idx - 1);
	cur->right = creatingTree(preorder, inorder, inorder_idx + 1, right);
	return cur;
}
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder)
{
	if (preorder.empty())
		return nullptr;
	return creatingTree(preorder, inorder, 0, inorder.size() - 1);
}
};
