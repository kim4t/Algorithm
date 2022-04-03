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
