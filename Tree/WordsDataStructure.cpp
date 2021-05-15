class WordDictionary {
    unordered_map<char,WordDictionary*> um = {};
    bool isEnd = false;
    WordDictionary* node;
public:
    /** Initialize your data structure here. */
    WordDictionary() {}
    
    void addWord(string word) {
        node = this;
        for(char c: word)
        {
            if(node->um.find(c)==um.end())
                node->um[c] = new WordDictionary();
            node = node->um[c];
        }
        node->isEnd = true;
    }
    
    bool search(string word) {
        bool found = false;
        dfs(0,word,this,found);
        return found;
    }
    void dfs(int curIdx, string &word, WordDictionary* cur, bool &found)
    {
        if (found == true || cur == NULL) {
            return;
        }
        if (curIdx == word.size() && cur->isEnd) {
            found = true;
            return;
        }
        char c = word[curIdx];
        if (c == '.') {
            for (auto it : cur->um) {
                dfs(curIdx + 1, word, it.second, found);
            }
        }
        else {
            if (cur->um[c] != NULL) {
                dfs(curIdx + 1, word, cur->um[c], found);
            }
        }
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */
