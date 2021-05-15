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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int size = nums.size();
        if(size==0)
            return nullptr;
        if(size==1)
            return new TreeNode(nums[0]);
        
        int mid = size/2;
        
        TreeNode* newNode = new TreeNode(nums[mid]);
        
        vector<int> left(nums.begin(),nums.begin()+mid);
        vector<int> right(nums.begin()+mid+1,nums.end());
        
        newNode->left = sortedArrayToBST(left);
        newNode->right = sortedArrayToBST(right);
        return newNode;
    }
};
