class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;
        for(int i=0;i<n;i++) {
            long long prodVal = nums[i];
            long long gcdVal = nums[i];
            long long lcmVal = nums[i];

            for(int j=i+1;j<n;j++) {
                prodVal = prodVal * nums[j];
                gcdVal = gcd(gcdVal, nums[j]);
                lcmVal = lcm(lcmVal, nums[j]);
                if(prodVal > gcdVal * lcmVal) break;
                if(prodVal == gcdVal * lcmVal) res = max(res, j - i + 1);
            }
        }
        return res;
    }
};