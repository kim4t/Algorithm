//leetcode 287

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
       for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]);
            nums[index] *= -1;
            if(nums[index] > 0)
                return index;
        }    
        return -1;
    }
};
