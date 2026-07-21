class Solution {
public:

    int even(vector<int>& arr)
    {
        int sum = 0;
        int ans = 0;

        for(int i = 1; i < arr.size(); i += 2)
        {
            sum += arr[i];
            ans += arr[i];
        }

        for(int i = 1; i < arr.size() - 1; i += 2)
        {
            int curr = sum - arr[i];
            curr += arr[i] + arr[i - 1] + arr[i + 1];
            ans = max(ans, curr);
        }

        return ans;
    }

    int odd(vector<int>& arr)
    {
        int sum = 0;
        int ans = 0;

        for(int i = 0; i < arr.size(); i += 2)
        {
            sum += arr[i];
            ans += arr[i];
        }

        for(int i = 2; i < arr.size() - 1; i += 2)
        {
            int curr = sum - arr[i];
            curr += arr[i] + arr[i - 1] + arr[i + 1];
            ans = max(ans, curr);
        }

        return ans;
    }

    int maxActiveSectionsAfterTrade(string s)
    {
        vector<int> arr;
        int cnt = 1;

        for(int i = 1; i < s.size(); i++)
        {
            if(s[i] == s[i - 1])
                cnt++;
            else
            {
                arr.push_back(cnt);
                cnt = 1;
            }
        }

        arr.push_back(cnt);

        if(s[0] == '0')
            return even(arr);

        return odd(arr);
    }
};