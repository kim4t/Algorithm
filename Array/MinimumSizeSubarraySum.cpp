class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int start = 0;
        int res = nums.size()+1;
        for(int i=0;i<nums.size();i++)
        {
            target -= nums[i];
            while(target<=0)
            {
                res = min(res, i-start+1);
                target += nums[start++];
            }
        }
        return res%(nums.size()+1);
    }
};
