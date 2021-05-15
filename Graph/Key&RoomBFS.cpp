class Solution {
    unordered_set<int> us;
    queue<int> q;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        us.emplace(0);
        q.push(0);
        while(q.size()>0)
        {
            int roomIdx = q.front();
            q.pop();
            for(int& key : rooms[roomIdx])
            {
                if(us.find(key)==us.end())
                {
                    us.emplace(key);
                    q.push(key);
                }
            }
        }
        if(rooms.size() == us.size())
            return true;
        return false;
    }
};
