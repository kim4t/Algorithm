class Solution {
    public int maxEnvelopes(int[][] envelopes) {
     Arrays.sort(envelopes, (a,b) -> a[0]==b[0]?b[1]-a[1]:a[0]-b[0]);
     int[] height = new int[envelopes.length];
     for(int i=0;i<height.length;i++)
         height[i] = envelopes[i][1];
        
        return LIS(height);
    }
    
    int LIS(int[] arr){
        List<Integer> list = new ArrayList<>();
        list.add(arr[0]);
        for(int i=1;i<arr.length;i++){
            int v = binarySearch(list,arr[i]);
            if(v==-1)
                list.add(arr[i]);
            else
                list.set(v,arr[i]);
        }
        return list.size();
    }
    int binarySearch(List<Integer> list, int target){
        int left = 0;
        int right = list.size()-1;
        int res = Integer.MAX_VALUE;
        
        while(left<=right){
            int mid = left + (right-left)/2;
            if(list.get(mid)>=target){
                 right = mid-1;
                 res = Math.min(res,mid);
            }
            else
                left = mid+1;    
        }
        
        return res == Integer.MAX_VALUE?-1:res;
    }
}
