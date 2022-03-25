//leetcode 125
class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";
        string s2;
        for(auto& c:s)
        {
            if(isalnum(c))
                s1+=toupper(c);
        }
        s2 = s1;
        reverse(s2.begin(),s2.end());
        return s1==s2;
    }
};
