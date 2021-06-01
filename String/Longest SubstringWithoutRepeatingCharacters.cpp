// leetcode 3
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxLen = 0;
        int start = -1;
        unordered_map<char,int> um;
        for(int i=0;i<s.length();i++)
        {
            if(um.find(s[i]) != um.end())
                start = max(start, um[s[i]]);
            
            um[s[i]] = i;
            maxLen = max(maxLen, i-start);
        }
        return maxLen;
    }
};
