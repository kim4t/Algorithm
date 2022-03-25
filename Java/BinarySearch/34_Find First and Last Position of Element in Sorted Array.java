class Solution {
    public int[] searchRange(int[] nums, int target) {
        return new int[]{findStart(nums,target),findEnd(nums,target)};
    }
    public int findStart(int[] nums, int target){
        int left = 0;
        int right = nums.length-1;
        int idx = -1;
        
        while(left <= right){
            int mid = left +(right-left)/2;
            if(nums[mid] < target)
                left  = mid +1;
            else
                right = mid-1;
            if(nums[mid] == target)
                idx = mid;
        }
        return idx;
    }
    public int findEnd(int[] nums, int target){
        int left = 0;
        int right = nums.length-1;
        int idx = -1;
        
         while(left <= right){
            int mid = left +(right-left)/2;
            if(nums[mid] > target)
                right = mid-1;
             else
                left = mid+1;
             if(nums[mid] == target)
                idx = mid;
        }
        return idx;
    }
}
