class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        if(n == 1) return 1;
        unordered_map<int, int> freq;
        int len = -1;
        int j = 0;
        for(int i=0;i<n;i++) {
            freq[nums[i]]++;
            while(freq[nums[i]] > k) {
                freq[nums[j]]--;
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};