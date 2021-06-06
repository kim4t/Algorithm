//leetcode 242
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int> um;
        for(char& c: s)
            um[c]++;
        for(char& c: t)
            um[c]--;
        for(auto e = um.begin(); e != um.end(); e++)
            if(e->second != 0)
                return false;
        return true;
    }
};
