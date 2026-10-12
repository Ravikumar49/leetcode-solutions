class Solution {
public:
    void countBits(vector<int>& ans, int n) {
        for(int i=0;i<32;i++) {
            if((n >> i) & 1) ans[i]++;
        }
    }
    int maxSum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> bitSet(32, 0);
        for(int i=0;i<n;i++) {
            countBits(bitSet, nums[i]);
        }
        int sum = 0;
        long long MOD = 1000000007;
        while(k > 0) {
            int num = 0;
            for(int i=0;i<32;i++) {
                if(bitSet[i] > 0) {
                    num |= (1 << i);
                    bitSet[i]--;
                }
            }
            long long val = (1LL * num * num) % MOD;
            sum = (sum + val) % MOD;
            k--;
        }
        return sum;
    }
};