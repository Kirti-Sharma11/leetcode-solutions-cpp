class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int sum=0,mul=1;
        for(char& ch : s)
        {
            sum+=(ch-'0');
            mul*=(ch-'0');
        }
        return (n%(sum+mul)==0);
    }
};