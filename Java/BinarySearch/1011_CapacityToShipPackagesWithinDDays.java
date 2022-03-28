class Solution {
    public int shipWithinDays(int[] weights, int days) {
        int left=0;
        int right=0;
        int res = Integer.MAX_VALUE;
        for(int i: weights){
            left = Math.max(left,i);
            right += i;
        }
       
        while(left <= right){
          int mid = left +(right-left)/2;
            if(numOfDayNeededForCapacity(weights,mid)>days){
                  left = mid+1; 
            } 
            else{
                  right = mid-1;
                  res = mid;
            } 
        }
       
        return res;
    }
    
    int numOfDayNeededForCapacity(int[] weights, int capacity){
        int cur = 0;
        int res = 1;
        for(int i: weights){
            cur +=i;
            if(cur > capacity){
                res++;
                cur = i;
            }   
        }
        return res;
    }
}
