class Solution {
    int row,col,i,j,newi,newj;
    queue<pair<int,int>> q;
    vector<vector<int>> directions {{-1,-1},{-1,0},{-1,1},{0,-1},{0,1},{1,-1},{1,0},{1,1}};
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        row = grid.size();
        col = grid[0].size();
        if(grid[0][0] !=0 || grid[row-1][col-1] != 0)
            return -1;
        q.push({0,0});
        grid[0][0] = 1;
        while(q.size()>0)
        {
            i = q.front().first;
            j = q.front().second;
            if(i==row-1 && j == col-1)
                return grid[i][j];
            q.pop();
            for(vector<int>& d : directions)
            {
                newi = i+d[0];
                newj = j+d[1];
                if(newi>=0 && newi<row && newj>=0 && newj<col && grid[newi][newj]==0)
                {
                    q.push({newi,newj});
                    grid[newi][newj] = grid[i][j]+1;
                }
            }
        }
        return -1;
    }
};
