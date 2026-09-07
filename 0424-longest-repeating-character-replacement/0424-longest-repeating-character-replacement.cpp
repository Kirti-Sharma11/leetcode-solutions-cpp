class Solution {
public:
    int characterReplacement(string s, int k) {
        int start = 0;
        int ans = 0;
        int maxFreq = 0;

        unordered_map<char,int> mp;

        for(int end = 0; end < s.size(); end++)
        {
            mp[s[end]]++;

            maxFreq = max(maxFreq, mp[s[end]]);

            int len = end - start + 1;
            int changes = len - maxFreq;

            while(changes > k)
            {
                mp[s[start]]--;
                start++;

                len = end - start + 1;
                changes = len - maxFreq;
            }

            ans = max(ans, end - start + 1);
        }

        return ans;
    }
};