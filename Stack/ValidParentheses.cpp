// leetcode 20
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char,char> um;
        um[')'] = '(';
        um['}'] = '{';
        um[']'] = '[';
        
        for(char& c: s)
        {
            if(c == '(' || c == '{' || c == '[')
                stk.push(c);
            else
            {
                if(stk.empty() || stk.top() != um[c])
                    return false;
                stk.pop();
            }
          
               
        }
        return stk.empty();
    }
};
