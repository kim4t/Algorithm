class Trie
{
public:
   unordered_map<char, Trie*> um;
   string word;
   Trie* cur;
    
   void add(string str)
   {
        cur = this;
        for(char ch : str)
        {
            if(cur->um.find(ch) == um.end())
                    cur->um[ch] = new Trie;
             cur = cur->um[ch];
        }
        cur->word = str;     
    }        
};

class Solution {
    int row;
    int col;
public:
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
    
        if(board.empty() || board[0].empty())
            return {{}};
        row = board.size();
        col = board[0].size();
        
        Trie* root  = new Trie();
        for(string& str: words)
            root->add(str);
        
      
        vector<string> res;
        
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                BT(board, root, res , i ,j); 
            }
        }
        return res;
    }
    
    void BT(vector<vector<char>>& board, Trie* cur, vector<string>& res, int r, int c)
    {
       if(r<0 || r == row || c<0 || c == col)
           return;
        
       char ch = board[r][c];
       if (ch == '*' || !cur->um[ch])
           return;
        
        cur = cur->um[ch];
        if(cur->word.size()>0)
        {
            res.push_back(cur->word);
            cur->word = "";
        }
        
        board[r][c] = '*';
        BT(board, cur, res, r+1, c);
        BT(board, cur, res, r-1, c);
        BT(board, cur, res, r, c+1);
        BT(board, cur, res, r, c-1);
        board[r][c] = ch;        
    }
};
