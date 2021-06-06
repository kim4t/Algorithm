// leetcode 560
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0;
        unordered_map<int,vector<int>> um;
        int res = 0;
        um[0].push_back(-1);
        
        for(int i=0;i<nums.size();i++)
        {
            sum += nums[i];
            int target = sum - k;
            if(um.find(target) != um.end())
                res += um[target].size();
            um[sum].push_back(i);
        }
        return res;
    }
};
