class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        if(graph.empty())
            return true;
        
        vector<int> color(graph.size());
        queue<int> q;
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i])  continue;
            
            color[i] = 1;
            q.push(i);
            while(!q.empty())
            {
                int cur = q.front();
               
                for(auto& e : graph[cur])
                {
                    if(color[e] == 0)
                    { 
                        color[e] = color[cur]==1?2:1;
                        q.push(e);
                    }  
                    else if(color[e] == color[cur] )
                        return false;     
                }
                 q.pop();
            }
        }
        return true;
       
    }
   
};
