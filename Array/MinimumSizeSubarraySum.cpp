class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int res = nums.size()+1;
        int left = 0;
        for(int i=0;i<nums.size();i++)
        {
            target -= nums[i];
            while(target <=0)
            {
                res = min(res,i-left+1);
                target += nums[left++];
            }
        }
        return res % (nums.size()+1);
    }
};
