class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        
        int n = nums.size();
        
        int small = INT_MAX;
        int big = INT_MIN;
        int index = 0, index2 = 0;

        // smallest, largest aur unke indices find karo
        for(int i = 0; i < n; i++)
        {
            if(nums[i] < small)
            {
                small = nums[i];
                index = i;
            }

            if(nums[i] > big)
            {
                big = nums[i];
                index2 = i;
            }
        }

        // index1 ko pehle aur index2 ko baad mein rakho
        int first = min(index, index2);
        int second = max(index, index2);

        // 1. Dono left se delete
        int option1 = second + 1;

        // 2. Dono right se delete
        int option2 = n - first;

        // 3. First left se, second right se
        int option3 = (first + 1) + (n - second);

        return min({option1, option2, option3});
    }
};