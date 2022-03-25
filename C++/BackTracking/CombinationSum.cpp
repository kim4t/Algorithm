class Solution {
public:
   vector<vector<int>> res;
   vector<int> v;
 void BT(int prevIdx, int targetSum, vector<int>& candidates)
{
	 if (targetSum == 0)
	 {
		 res.push_back(v);
		 return;
	 }
	 else if (targetSum < 0)
		 return;

	 for (int i = prevIdx; i < candidates.size(); i++)
	 {
		 int num = candidates[i];
		 v.push_back(num);
		 BT(i, targetSum-num, candidates);
		 v.pop_back();
	 }
		
}
vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
{
	if (candidates.size() == 0) 
		return { {} };
	vector<int>v;
	BT(0, target, candidates);
	return res;
}
};
