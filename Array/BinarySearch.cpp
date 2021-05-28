class Solution {
public:
    int search(vector<int>& nums, int target) {
        return BS(nums,target,0,nums.size()-1);
    }
    int BS(vector<int>& nums, int& target, int l, int r)
    {
        if(r>=l)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                return BS(nums, target, l, mid-1);
            else if(nums[mid] < target)
                return BS(nums, target, mid+1, r);
        }
        return -1;
    }
};
