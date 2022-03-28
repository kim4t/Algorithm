class Solution {
    public int preimageSizeFZF(int k) {
       long left= 0;
       long right = Long.MAX_VALUE;
        
        while(left <= right){
           long mid = left+(right-left)/2;
           long numOfZeroes = trailingZeroes(mid);
            
            if(numOfZeroes == k)
                return 5;
            else if(numOfZeroes < k)
                left = mid+1;
            else
                right = mid-1;
        }
        return 0;
    }
    
    private long trailingZeroes(long k){
        return k==0?0:(k/5)+trailingZeroes(k/5);
    }
    
}
