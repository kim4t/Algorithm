// leetcode 380
class RandomizedSet {
    unordered_map<int,int> um;
    vector<int>v;
public:
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if(um.find(val) != um.end())
            return false;
        v.push_back(val);
        um[val] = v.size()-1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if(um.find(val) == um.end())
            return false;
        um[v.back()] = um[val];           
        swap(v.back(), v[um[val]]);
        v.pop_back();
        um.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return v[rand() % v.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
