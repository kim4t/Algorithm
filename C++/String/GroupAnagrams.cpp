// leetcode 49
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> um;
        vector<vector<string>> res;
        for(int i=0;i<strs.size();i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            um[s].push_back(strs[i]);
        }
         for(auto vec = um.begin(); vec != um.end(); vec++)
        {
         
            res.push_back(vec->second);
        }
        return res;
    }
};
