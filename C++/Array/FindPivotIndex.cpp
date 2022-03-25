class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int rightSum = accumulate(nums.begin(),nums.end(),0);
        int leftSum = 0;
        int pastPivot = 0;
        for(int i=0;i<nums.size();i++)
        {
            rightSum -= nums[i];
            leftSum += pastPivot;
            if(leftSum == rightSum)
                return i;
            pastPivot = nums[i];
        }
        return -1;
    }
};
