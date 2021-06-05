// leetcode 227
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        long num = 0;
        char sign = '+';
        s += '+';
        for(char& c: s)
        {
            if(isdigit(c))
                num = num*10 + c-'0';
            else if(isspace(c))
                continue;
            else
            {
                if(sign == '+')
                    stk.push(num);
                else if(sign == '-')
                    stk.push(-num);
                else if(sign == '*')
                    stk.top() *= num;
                else if(sign == '/')
                    stk.top() /= num;
                num = 0;
                sign = c;
            }
        }
        long res = 0;
        while(!stk.empty())
        {
            res += stk.top();
            stk.pop();
        }
        return res;
    }
};
