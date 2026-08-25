class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> val(nums.begin(), nums.end());
        int ans = k;
        while(val.count(ans)) {
            ans += k;;
        }
        return ans;
    }
};