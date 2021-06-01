// leetcode 70
// F(n) = F(n-1) + F(n-2)

// Top down
class Solution {
    vector<int> v{0,1,2};
public:
    int climbStairs(int n) {
        if(n<v.size())
            return v[n];
        int val = climbStairs(n-1) + climbStairs(n-2);
        v.push_back(val);
        return val;
    }
};

// Bottom up
class Solution {
    vector<int> v{0,1,2};
public:
    int climbStairs(int n) {
        for(int i=3;i<=n;i++)
        {
            int val = v[i-2] + v[i-1];
            v.push_back(val);
        }
        return v[n];
    }
};
