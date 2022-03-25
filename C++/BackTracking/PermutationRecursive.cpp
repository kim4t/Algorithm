class Solution {
public:
    vector<vector<int>> res;
    void BT(int len, vector<int> v, vector<int>& nums)
    {
        if(len == nums.size())
        {
            res.push_back(v);
            return;
        }
        for(auto& e: nums)
        {
            if(find(v.begin(), v.end(), e) == v.end())
            {
                v.push_back(e);
                BT(len+1,v,nums);
                v.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        if(nums.size()==0) return {{}};
        vector<int> v;
        BT(0,v,nums);
        return res;
    }
};
