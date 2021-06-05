// leetcode 224
class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        long res=0, n = 0;
        int sign = 1;
        stk.push(1);
        s += '+';
        for(char&c : s)
        {
            if(isdigit(c))
                n = n*10 + c-'0';
            else if(c == '+' || c == '-')
            {
                res += n * sign * stk.top();
                if(c == '+')
                    sign = 1;
                else
                    sign = -1;
                n = 0;
            }
            else if(c == '(')
            {
                stk.push(sign * stk.top());
                sign = 1;
            }
            else if(c == ')')
            {
                res += n * sign * stk.top();
                n = 0;
                stk.pop();
            }
        }
        return res;
    }
};
