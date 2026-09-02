class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {

        vector<int> odd1, odd2;
        vector<int> even1, even2;

        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] % 2)
                odd1.push_back(nums[i]);
            else
                even1.push_back(nums[i]);
        }

        for(int i = 0; i < target.size(); i++)
        {
            if(target[i] % 2)
                odd2.push_back(target[i]);
            else
                even2.push_back(target[i]);
        }

        sort(odd1.begin(), odd1.end());
        sort(odd2.begin(), odd2.end());

        sort(even1.begin(), even1.end());
        sort(even2.begin(), even2.end());

        long long ans = 0;

        for(int i = 0; i < odd1.size(); i++)
        {
            if(odd1[i] > odd2[i])
                ans += (odd1[i] - odd2[i]) / 2;
        }

        for(int i = 0; i < even1.size(); i++)
        {
            if(even1[i] > even2[i])
                ans += (even1[i] - even2[i]) / 2;
        }

        return ans;
    }
};