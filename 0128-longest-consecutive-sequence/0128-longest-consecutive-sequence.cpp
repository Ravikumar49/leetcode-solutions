class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> val(nums.begin(), nums.end());
        int longest = 0;
        for(int x : val) {
            if(!val.count(x-1)) {
                int current = x;
                int len = 1;
                while(val.count(current+1)) {
                    len++;
                    current++;
                }
                longest = max(longest, len);
            }
        }
        return longest;
    }
};