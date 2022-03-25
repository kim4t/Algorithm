class Solution {
    unordered_set<int> seen;
    bool start = true;
   
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty())
            return true;
        
        vector<int> color(graph.size(),0);
        for(int i=0;i<graph.size();i++)
        {
           if(!DFS(graph, color,i))
               return false;
        }
        return true;
    }
    bool DFS(vector<vector<int>>& graph, vector<int>& color, int idx)
    {
        if(graph[idx].empty())
            return true;
        
        seen.emplace(idx);
        if(start)
        {
            color[idx] = 1;
            start = false;
        }
        for(auto& e : graph[idx])
        {
            if(seen.find(e) == seen.end())
            {
                color[e] = color[idx]==1?-1:1;
                DFS(graph,color,e);
            }
            else if(color[e] == color[idx])
                return false;
        }
        return true;
        
    }
};
