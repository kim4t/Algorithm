// leetcode 14
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs.back();
        string res = "";
        for(int i=0;i<first.size();i++)
        {
            if(first[i] == last[i])
                res += first[i];
            else
                break;
        }
        return res;
    }
};
