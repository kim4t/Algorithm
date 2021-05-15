class Solution {
public:
  vector<string> res;
vector<string> hm{ "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz" };

void BT(int index, string letter, string digits)
{
	if (index >= digits.length())
	{
		res.push_back(letter);
		return;
	}
	int num = digits[index]-'0';
	string s = hm[num];
	for (auto e : s)
	{
		letter += e;
		BT(index + 1, letter, digits);
		letter.pop_back();
	}
	
}
vector<string> letterCombinations(string digits) 
{
	if (digits.length() == 0)
		return {};
	string letter = "";
	BT(0, letter, digits);
	return res;
}
};
