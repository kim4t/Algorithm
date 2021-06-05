//leetcode 394
class Solution {
public:
    string decodeString(string s) {
        stack<string> stk;
        stack<int> count;
        int n = 0;
        stk.push("");
        
        for(char& c : s)
        {
          if(isalpha(c))
              stk.top()+=c;
        
          else if(isdigit(c))
              n = n*10 + c-'0';
            
          else if(c == '[')
          {
              stk.push("");
              count.push(n);
              n = 0;
          }
          else
          {
              string curStr = stk.top();
              string newStr = "";
              
              for(int i=0;i<count.top();i++)
                  newStr += curStr;
              
              stk.pop();
              count.pop();
              stk.top() += newStr;
          }   
        }
       return stk.top();
    }
};
