// leetcode 48

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        for(int i=0;i<matrix.size();i++)
        {
             for(int j=i;j<matrix.size();j++)
             {
                 swap(matrix[j][i],matrix[i][j]);
             }
             reverse(matrix[i].begin(),matrix[i].end());
        }
           
    }
};
