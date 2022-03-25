class Solution {
public:
    vector<vector<int>> res;
   void BT(int idx, vector<int>& letter, vector<int>& nums)
{
	if (idx == nums.size())
	{
		res.push_back(letter);
		return;
	}
	int n = nums[idx];
	letter.push_back(n);
	BT(idx + 1, letter, nums);
	letter.pop_back();
	BT(idx + 1, letter, nums);
}
vector<vector<int>> subsets(vector<int>& nums) 
{
	if (nums.size() == 0)
		return {{}};
	vector<int> letter;
	BT(0, letter, nums);
	return res;
}
};
