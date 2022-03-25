class Solution {
    int row;
    int col;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.empty())
            return 0;
        if(grid[0].empty())
            return 0;
        
        row = grid.size();
        col = grid[0].size();
        int count = 0;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j] == '1')
                {
                    count++;
                    BFS(grid,i,j);
                }
            }
        }
        return count;
    }
    
    void BFS(vector<vector<char>>& grid, int i, int j)
    {
        if(i<0 || i==row || j<0 || j==col || grid[i][j] != '1')
            return;
        grid[i][j] = '0';
        BFS(grid,i-1,j);
        BFS(grid,i+1,j);
        BFS(grid,i,j-1);
        BFS(grid,i,j+1);
    }
};
