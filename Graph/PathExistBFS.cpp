/*1 is wall, 0 is path 
  start with (0,0) return path to (size-1,size-1) exist or not
  assume board[0][0] == 0
*/
class GraphPath
{
	int row;
	int col;
	int i, j,newi,newj;
	queue<pair<int, int>> q;
	vector<vector<int>> directions{ {-1,0},{1,0},{0,-1},{0,1} };
public:
	bool pathExist(vector<vector<int>>& board)
	{
		row = board.size();
		col = board[0].size();
		
		q.push({ 0,0 });
		while (q.size() > 0)
		{
			i = q.front().first;
			j = q.front().second;
			
			if (i == row - 1 && j == col - 1 && board[i][j] == 0)
				return true;
			for (auto& d : directions)
			{
				 newi = i + d[0];
				 newj = j + d[1];
				 if (newi >= 0 && newi < row && newj >= 0 && newj < col && board[newi][newj] == 0)
				 {
					 q.push({ newi,newj });
					 board[i][j] = 1;
				 }
				 
			}
			q.pop();
		}
		return false;
	}
	

};
