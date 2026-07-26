class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int prod = INT_MIN;
        for(int i=0;i<n-2;i++) {
            int j = i+1, k = n-1;
            while(j < k) {
                int curr = nums[i] * nums[j] * nums[k];
                prod = max(prod, curr);
                j++;
                k--;
            }
        }
        return prod;
    }
};