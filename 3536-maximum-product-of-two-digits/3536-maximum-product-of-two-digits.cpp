class Solution {
public:
    int maxProduct(int n) {
        vector<int>ans;
        while(n)
        {
          int m=n%10;
          ans.push_back(m);
          n=n/10;
        }
        sort(ans.begin(),ans.end());
        int m=ans.size();
        int product=ans[m-1]*ans[m-2];
        return product;
    }
};