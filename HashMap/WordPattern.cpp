// leetcode 290
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> v;
        string str = "";
        for(char&c : s)
        {
            if(isspace(c))
            {
                v.push_back(str);
                str = "";
            }
            else
                str+=c;
        }
        v.push_back(str);
        if(v.size() != pattern.length())
            return false;
        
        unordered_map<char,string> um;
        unordered_map<string,char> um2;
        for(int i=0;i<pattern.length();i++)
        {
            if(um.find(pattern[i]) == um.end())
                um[pattern[i]] = v[i];
            else if(um[pattern[i]] != v[i])
                return false;
            if(um2.find(v[i]) == um2.end())
                um2[v[i]] = pattern[i];
            else if(um2[v[i]] != pattern[i])
                return false;
        }
        return true;
    }
};
