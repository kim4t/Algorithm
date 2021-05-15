class Solution {
public:
    vector<vector<int>> res;


vector<vector<int>> subsets(vector<int>& nums) 
{
	stack<tuple<int, vector<int>>>stk;
	vector<int> v;
	stk.push(make_tuple(0, v));

	int lev;
	while (stk.size() > 0)
	{
		lev = get<0>(stk.top());
		v = get<1>(stk.top());
		stk.pop();

		if (lev == nums.size())
		{
			res.push_back(v);
			continue;
		}
		int n = nums[lev];
		v.push_back(n);
		stk.push(make_tuple(lev + 1, v));
		v.pop_back();
		stk.push(make_tuple(lev + 1, v));
	}
	return res;
}
};
