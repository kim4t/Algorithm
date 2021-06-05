//leetcode 1209class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<char> stk;
        stack<int> count;
        for(char& c : s)
        {
           if(!stk.empty() && stk.top() == c)
           {
               if(count.top() == k-1)
               {
                   count.pop();
                   for(int i=0;i<k-1;i++)
                       stk.pop();
               }
               else
               {
                   count.top() +=1;
                   stk.push(c);
               }
                  
           }
           else
            {
               stk.push(c);
               count.push(1);
            }
           
        }
        string res = "";
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
