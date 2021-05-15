class Solution {
    int oldColor;
    int newColor;
    int row;
    int col;
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image.empty() || image[0].empty() ||image[sr][sc] == newColor)
            return image;
        
        oldColor = image[sr][sc];
        this->newColor = newColor;
        row = image.size();
        col = image[0].size();
        
        BFS(image,sr,sc);
        
        return image;
    }
    void BFS(vector<vector<int>>& image, int i, int j)
    {
        if(i<0 || i == row || j<0 || j==col || image[i][j] != oldColor)
            return;
        
        image[i][j] = newColor;
        
        BFS(image,i-1,j);
        BFS(image,i+1,j);
        BFS(image,i,j-1);
        BFS(image,i,j+1);
    }
};
