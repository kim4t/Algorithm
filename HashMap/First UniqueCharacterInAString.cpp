// leetcode 387
class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> um;
        for(char&c : s)
            um[c]++;
        for(int i=0;i<s.length();i++)
        {
            if(um.find(s[i]) != um.end() && um[s[i]] == 1)
               return i;
        }
        return -1;
    }
};
