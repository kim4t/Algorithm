/*1 is wall, 0 is path 
  start with (0,0) return path to (size-1,size-1) exist or not
  assume board[0][0] == 0
*/
class GraphPath
{
	int row;
	int col;
	bool path = false;
public:
	bool pathExist(vector<vector<int>>& board)
	{
		row = board.size();
		col = board[0].size();
		DFS(board, 0, 0);
		return path;
	}
	void DFS(vector<vector<int>>& board, int i, int j)
	{
		if (i < 0 || i == row || j < 0 || j == row || board[i][j] == 1)
			return;
		if (i == row - 1 && j == col - 1 && board[i][j] == 0)
		{
			path = true;
			return;
		}
			
		board[i][j] = 1;
		DFS(board, i - 1, j);
		DFS(board, i + 1, j);
		DFS(board, i, j - 1);
		DFS(board, i, j + 1);
						
	}

};

int main()
{
	vector<vector<int>> v{ {0,1,0,0,0},
						   {0,1,0,1,0},
						   {0,0,0,1,1},
						   {1,1,0,0,0},
						   {0,0,1,1,0} };

	cout << GraphPath().pathExist(v);
	return 0;
}
