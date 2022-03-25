class Solution {
public:
    vector<string> res;
int open_c;
int close_c;

void BT(int open_c, int close_c, string& letters)
{
	if (open_c == 0 && close_c == 0)
	{
		res.push_back(letters);
		return;
	}
	// open whenever we can open
	if (open_c > 0)
	{
		letters += '(';
		BT(open_c - 1, close_c, letters);
		letters.pop_back();
	}
	
	if (open_c < close_c)
	{
		letters += ')';
		BT(open_c, close_c-1, letters);
		letters.pop_back();
	}
	
}
vector<string> generateParenthesis(int n) 
{
	open_c = n;
	close_c = n;
	string letters = "";
	BT(open_c, close_c, letters);
	return res;
}
};
