class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> val(nums.begin(), nums.end());
        int mul = k;
        while(true) {
            if(!val.count(k)) {
                break;
            }
            k += mul;
        }
        return k;
    }
};