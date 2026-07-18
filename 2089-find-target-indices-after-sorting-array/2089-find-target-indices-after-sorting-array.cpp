class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin() , nums.end());
        vector<int>ans;
        for( int x=0 ; x<nums.size() ; x++)
        {
            if(nums[x]==target)
            ans.push_back(x);
        }
        return ans;
    }
};