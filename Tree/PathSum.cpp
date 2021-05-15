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
    vector<vector<int>> res;
public:
   void BT(TreeNode* cur,int targetSum, vector<int>& v)
{
	if (cur->left == nullptr && cur->right == nullptr)
	{
		if (cur->val==targetSum)
		{
			v.push_back(cur->val);
			res.push_back(v);
			v.pop_back();
		}
		return;
	}
	int val = cur->val;
	if (cur->left)
	{
		v.push_back(val);
		BT(cur->left, targetSum - val, v);
		v.pop_back();
	}
		
	if (cur->right)
	{
		v.push_back(val);
		BT(cur->right, targetSum - val, v);
		v.pop_back();
	}
		
}
vector<vector<int>> pathSum(TreeNode* root, int targetSum) 
{
	if (root == nullptr)
		return res;
	TreeNode* cur = root;
	vector<int> v;
	BT(cur,targetSum, v);
    return res;
}
};
