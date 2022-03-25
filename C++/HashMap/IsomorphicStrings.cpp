// leetcode 205
class Solution {
public:
    bool isIsomorphic(string s, string t) 
    {
        if(s.length() != t.length())
            return false;
        unordered_map<char,char> um;
        for(int i=0;i<s.length();i++)
        {
            if(um.find(s[i]) == um.end())
                um[s[i]] = t[i];
            else if(um[s[i]] != t[i])
                return false;    
        }
        um.clear();
        for(int i=0;i<s.length();i++)
        {
            if(um.find(t[i]) == um.end())
                um[t[i]] = s[i];
            else if(um[t[i]] != s[i])
                return false;    
        }
        return true;
    }
};
