//leetcode 56

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
       vector<vector<int>>res;
       sort(intervals.begin(),intervals.end());
       vector<int>curVec{intervals[0][0],intervals[0][1]};
       
       for(auto&nextVec : intervals)
       {
          if(nextVec[0] > curVec[1])
          {
              res.push_back(curVec);
              curVec[0] = nextVec[0];
              curVec[1] = nextVec[1];
          }
          else
          {
              curVec[1] = max(nextVec[1],curVec[1]);
          }
       }
        res.push_back(curVec);
        return res;
    }
};
