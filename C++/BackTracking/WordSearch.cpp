class Solution {
public:
    int row;
    int col;
bool BT(int i, int j, int idx, string& word, vector<vector<char>>& board)
{
	//exit conditions
	if (idx == word.length())
		return true;
	else if (i < 0 || i == row || j < 0 || j == col || board[i][j] != word[idx])
		return false;
    
	//process
    char c = board[i][j];
    board[i][j] = '*';
	bool search_next = BT(i, j - 1, idx + 1, word, board)
		            || BT(i, j + 1, idx + 1, word, board)
		            || BT(i - 1, j, idx + 1, word, board)
		            || BT(i + 1, j, idx + 1, word, board);
    if(search_next)
        return true;
	board[i][j] = c;
	return false;
}

bool exist(vector<vector<char>>& board, string word) 
{
	if (word.length() == 0)
		return true;
    if(board.empty() || board[0].empty())
        return false;

	row = board.size();
	col = board[0].size();
    
	for (int y = 0; y < row; y++)
	{
		for (int x = 0; x < col; x++)
		{
			if(BT(y, x, 0, word, board))
				return true;
		}
	}
	return false;
}
};
