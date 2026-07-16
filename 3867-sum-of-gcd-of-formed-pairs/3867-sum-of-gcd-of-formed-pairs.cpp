class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> mx(n);
        vector<int> prefixGcd(n);
        mx[0] = prefixGcd[0] = nums[0];
        for(int i=1;i<n;i++) {
            mx[i] = max(mx[i-1], nums[i]);
            prefixGcd[i] = gcd(nums[i], mx[i]);
        }
        sort(prefixGcd.begin(), prefixGcd.end());
        int i = 0, j = n-1;
        long ans = 0;
        while(i < j) {
            ans += gcd(prefixGcd[i], prefixGcd[j]);
            i++;
            j--;
        }
        return ans;
    }
};