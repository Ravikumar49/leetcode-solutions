class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        for(int bit=0;bit<32;bit++) {
            int sum = 0;
            int mask = 1 << bit;
            for(int i=0;i<n;i++) {
                if((nums[i] & mask) != 0) sum++;
            }
            if(sum%3 == 1) ans |= mask;
        }
        return ans;
    }
};