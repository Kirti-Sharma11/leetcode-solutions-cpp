class Solution {
public:
    int maximumLengthSubstring(string s) {
        int ans=0;
        unordered_map<char,int>m;
        int i=0,j=0,n=s.size();
       while (j < n) 
       {
            m[s[j]]++;
            while (m[s[j]] > 2) 
            {
                m[s[i]]--;
                i++;
            }
            ans = max(ans, j - i + 1);
            j++;
        }
        return ans;
    }
};