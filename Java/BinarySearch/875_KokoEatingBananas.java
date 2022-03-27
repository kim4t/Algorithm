class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int left = 1;
        int right = 1000000000;
        
        while(left <= right){
            int mid = left + (right-left)/2;
            if(canEatAll(piles,h,mid))
                right = mid-1;
            else
                left = mid+1;
        }
        return left;
    }
    
    boolean canEatAll(int[] piles, int h, int k){
        int count = 0;
        for(int p: piles){
            count += p/k;
            if(p%k>0)
                count++;
            if(count > h)
                return false;
        }
        return count <= h;
    }
}
