class Solution {
    public int lengthOfLIS(int[] nums) {
        int[] DP = new int[nums.length];
        for(int i=nums.length-1;i>=0;i--){
            int max = 1;
            for(int j=i+1;j<nums.length;j++){
                if(nums[j] > nums[i])
                    max = Math.max(max,1+DP[j]);
            }
            DP[i] = max;
        }
        return Arrays.stream(DP).max().getAsInt();
    }
}
