class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k == 1) {
            unordered_map<int, int> freq;
            for(int i=0;i<nums.size();i++) {
                freq[nums[i]]++;
            }
            int ans = -1;
            for(auto x : freq) {
                if(x.second == 1 && x.first > ans) {
                    ans = x.first;
                }
            }
            return ans;
        }
        else if(k == nums.size()) {
            return *max_element(nums.begin(), nums.end());
        }
        else {
            int n = nums.size();
            unordered_map<int, int> freq;
            for(int i=0;i<n;i++) {
                freq[nums[i]]++;
            }
            int ans = -1;
            if(freq[nums[0]] == 1 && freq[nums[n-1]] == 1) {
                return max(nums[0], nums[n - 1]);
            }
            if(freq[nums[0]] > 1 && freq[nums[n-1]] == 1) {
                return nums[n-1];
            }
            else if(freq[nums[n-1]] > 1 && freq[nums[0]] == 1) {
                return nums[0];
            }
            else {
                return -1;
            }
        }
        return -1;
    }
};