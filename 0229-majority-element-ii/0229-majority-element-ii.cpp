class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;
        vector<int> res;
        int count = n/3;
        for(auto [val, f] : freq) {
            if(f > count) res.push_back(val);
        }
        return res;
    }
};