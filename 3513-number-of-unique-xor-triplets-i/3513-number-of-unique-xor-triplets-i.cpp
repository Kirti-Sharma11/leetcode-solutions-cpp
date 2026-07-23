class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) 
        return n;

        int bits = 0;
        while (n > 0) 
        {
            n >>= 1;
            bits++;
        }

        return 1 << bits;
    }
};