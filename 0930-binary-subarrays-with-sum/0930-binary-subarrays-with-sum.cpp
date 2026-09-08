class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        unordered_map<int,int> mp;

        int sum = 0;
        int count = 0;

        mp[0] = 1;

        for(int num : nums)
        {
            sum += num;

            int need = sum - goal;

            if(mp.find(need) != mp.end())
            {
                count += mp[need];
            }

            mp[sum]++;
        }

        return count;
    }
};