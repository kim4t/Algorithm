class Solution {
    public int lengthOfLIS(int[] nums) {
       List<Integer> list = new ArrayList<>();
        list.add(nums[0]);
        for(int i=1;i<nums.length;i++){
           int v = binarySearch(list,nums[i]);
           if(v==-1)
               list.add(nums[i]);
            else
                list.set(v,nums[i]);
               
        }
        return list.size();
    }
    
    int binarySearch(List<Integer> list, int target){
        int left = 0;
        int right = list.size()-1;
        int res = Integer.MAX_VALUE;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            if(list.get(mid) >= target){
                res = Math.min(res,mid);
                right = mid-1;
            } 
            else
                left = mid+1;
        }
        if(res != Integer.MAX_VALUE)
            return res;
        else
            return -1;
    }
}
