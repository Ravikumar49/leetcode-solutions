class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while(n > 0) {
            int rem = n%10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        for(int i=0;i<nums.size();i++) {
            nums[i] = sumOfDigits(nums[i]);
        }
        int ans = INT_MAX;
        for(auto &x : nums) {
            ans = min(ans, x);
        }
        return ans;
    }
};