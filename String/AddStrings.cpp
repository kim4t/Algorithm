// leetcode 415
class Solution {
public:
    string addStrings(string num1, string num2) {
        if(num1.size()<num2.size())
            swap(num1,num2);
        int dif = num1.size()-num2.size();
        string n2 = "";
        while(dif--) n2 += '0';
        n2 += num2;
        
        int k = 0;
        string res = "";
        for(int i=num1.size()-1;i>=0;i--)
        {
            int v = (num1[i]-'0') + (n2[i]-'0') + k;
            if(v>=10)
            {
                k = 1;
                v -= 10;
            }
            else
                k = 0;
            res += to_string(v);
        }
        if(k!=0)
            res += '1';
        reverse(res.begin(),res.end());
        return res;
    }
};
