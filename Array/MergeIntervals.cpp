//leetcode 56

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>>res;
       sort(intervals.begin(),intervals.end());
       vector<int>v{intervals[0][0],intervals[0][1]};
       
       for(auto&n : intervals)
       {
          if(n[0] <= v[1])
              v[1] = max(v[1],n[1]);
          else
          {
              res.push_back(v);
              v[0] = n[0];
              v[1] = n[1];
          }
       }
        res.push_back(v);
        return res;
    }
};
