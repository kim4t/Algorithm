// leetcode 746
// F(n) = min(F(n-2)+cost[n-2], F(n-1)+cost[n-1])
// Bottom  up
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> v{0,0};
        for(int i=2;i<=cost.size();i++)
        {
            int n = min(v[i-2]+cost[i-2], v[i-1]+cost[i-1]);
            v.push_back(n);
        }
        return v.back();
    }
};
