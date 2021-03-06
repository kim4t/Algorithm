//leetcode 162

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int left = 0;
        int right = nums.size()-1;
        if(nums.size()<=1)
            return 0;
        while(right>left)
        {
            int mid = (left+right)/2;
            if(nums[mid] < nums[mid+1])
                left = mid+1;
            else 
                right = mid;
        }
        return right;
    }
};
