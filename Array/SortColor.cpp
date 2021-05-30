//leetcode 75
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int p1=0;
        int p2 = nums.size()-1;
        int i;
        while(i<=p2)
        {
            if(nums[i] == 0 )
            {
                 swap(nums[i], nums[p1++]);
                 i++;
            }
            else if(nums[i] == 2)
            {
                swap(nums[i],nums[p2]);
                p2--;
            }
            else
                i++;
        }
    }
};
