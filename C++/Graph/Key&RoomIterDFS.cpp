class Solution {
    unordered_set<int> us;
    stack<int> stk;
    vector<int> keys;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
       us.emplace(0);
       stk.push(0);
       while(stk.size()>0)
       {
           int idx = stk.top();
           stk.pop();
           keys = rooms[idx];
           for(int& key : keys)
           {
               if(us.find(key) == us.end())
               {
                    stk.push(key);
                    us.emplace(key);
               }
           }
       }
       if(rooms.size() == us.size())
           return true;
        return false;
    }
};
