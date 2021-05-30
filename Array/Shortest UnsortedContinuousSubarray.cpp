//leetcode 581

//O(logN)
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> v = nums;
        sort(v.begin(),v.end());
        bool isFirst = true;
        int fIdx = 0, lIdx = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != v[i])
            {
                if(isFirst)
                {
                    isFirst = false;
                    fIdx = i;
                }
                lIdx = i;
            }
        }
        return lIdx == fIdx?0:lIdx-fIdx+1;
       
    }
};



//O(N)
