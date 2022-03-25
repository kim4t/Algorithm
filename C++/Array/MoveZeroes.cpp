// leet code 283
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int position = 0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i] != 0)
            {
                swap(nums[i],nums[position++]);
            }
        }
    }
};
