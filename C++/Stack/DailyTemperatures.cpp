// leetcode 739
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> res (t.size(),0);
        stack<pair<int,int>> stk;
        for(int i = t.size()-1; i>=0; i--)
        {
            int n = t[i];
            while(!stk.empty() && n>= stk.top().first)
                stk.pop();
            res[i] = stk.empty()?0: stk.top().second - i;
            stk.push({n,i});
        }
        return res;
    }
};
