// leetcode 704
// recursion
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


// loop
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        while(r>=l)
        {
            int mid = (l+r)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                r = mid-1;
            else if(nums[mid] < target)
                l = mid+1;
        }
        return -1;
        
    }
    
};
