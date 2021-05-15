class Solution {
    unordered_set<int> us;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) { 
        recurDFS(0,rooms);
        if(rooms.size() == us.size())
            return true;
        return false;
    }
    void recurDFS(int idx, vector<vector<int>>& rooms)
    {
        us.emplace(idx);
        for(auto& key: rooms[idx])
        {
            if(us.find(key) == us.end())
                recurDFS(key,rooms);
        }
    }
};
