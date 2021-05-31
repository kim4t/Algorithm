// leetcode 49
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string,vector<int>> um;
        for(int i=0;i<strs.size();i++)
        {
            string s = strs[i];
            sort(s.begin(),s.end());
            if(um.find(s) != um.end())
            {
                um[s].push_back(i);
            }
            else
            {
                vector<int> v{i};
                um[s] = v;
            }
        }
        for(auto vec = um.begin(); vec != um.end(); vec++)
        {
            vector<string> v; 
            for(int i=0;i<vec->second.size();i++)
            {
                int idx = vec->second[i];
                v.push_back(strs[idx]);
            }
            res.push_back(v);
        }
        return res;
    }
};
