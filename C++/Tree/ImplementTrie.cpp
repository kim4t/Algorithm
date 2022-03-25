class Trie {
    unordered_map<char,Trie*> um = {};
    bool isEnd = false;
    Trie* node;
public:
    /** Initialize your data structure here. */
    Trie() {}

    /** Inserts a word into the trie. */
    void insert(string word) {
        node = this;
        for(char c: word)
        {
            if(node->um.find(c) == um.end())
                node->um[c] = new Trie();
            node = node->um[c];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        node = this;
        for(char c: word)
        {
            if(!node->um.count(c))
                return false;
             node = node->um[c];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        node = this;
        for(char c: prefix)
        {
            if(node->um.count(c) == 0)
                return false;
             node = node->um[c];
        }
        return true;
    }
};
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
