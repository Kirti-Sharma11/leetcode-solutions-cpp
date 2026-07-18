class Solution {
public:
/*int gcd(int a,int b)
{
    while(b)
    {
        a%=b;
        swap(a,b);
    }
    return a;
}*/
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        return __gcd(nums[0],nums[n-1]);
    }
};