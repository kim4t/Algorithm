// leetcode 347
class Solution {
public:
    static bool foo(const pair<int,int>& i1, const pair<int,int>& i2)
    {
        return i1.second > i2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> um;
        for(int& n: nums)
            um[n]++;
        
        vector<pair<int,int>> v;
        for(auto e = um.begin(); e!=um.end(); e++)
            v.push_back({e->first,e->second});
        
        sort(v.begin(),v.end(),foo);
        
        vector<int> res;
        for(int i=0;i<k;i++)
            res.push_back(v[i].first);
        return res;
    }
};
