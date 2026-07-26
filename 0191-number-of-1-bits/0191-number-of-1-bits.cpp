class Solution {
public:
    int hammingWeight(int n) {
        vector<int>ans;
        while(n)
        {
           ans.push_back(n % 2);
           n = n / 2;
        }
        sort(ans.begin(),ans.end());
        int i=0;
        while(ans[i]!=1)
        {
            i++;
        }
        int s=ans.size();
        int count=s-i;
        return count;
    }
};