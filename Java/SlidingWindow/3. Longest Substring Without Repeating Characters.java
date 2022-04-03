class Solution {
    public int lengthOfLongestSubstring(String s) {
        int res = 0;
        int start = -1;
        Map<Character,Integer> hm = new HashMap<>();
        for(int i=0;i<s.length();i++){
            char c = s.charAt(i);
            if(hm.containsKey(c)){
                start = Math.max(start,hm.get(c));
            }
            hm.put(c,i);
            res = Math.max(res, i-start);
        }
        return res;
    }
}



class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0;
        int right = 0;
        int res = 0;
        
        Set<Character> hs = new HashSet<>();
        while(right<s.length()){
            char c = s.charAt(right);
            if(hs.contains(c)){
                while(hs.contains(s.charAt(right))){
                    hs.remove(s.charAt(left));
                    left++;
                } 
            }
            hs.add(c);
            res = Math.max(res,right-left+1);
            right++;
              
        }
        return res;
    }
}
