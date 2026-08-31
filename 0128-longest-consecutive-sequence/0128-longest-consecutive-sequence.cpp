class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> val(nums.begin(), nums.end());
        int len = 0;
        for(int x : val) {
            if(!val.count(x-1)) {
                int currLen = 0;
                int current = x;
                while(val.count(current)) {
                    currLen++;
                    current++;
                }
                len = max(len, currLen);
            }
        }
        return len;
    }
};