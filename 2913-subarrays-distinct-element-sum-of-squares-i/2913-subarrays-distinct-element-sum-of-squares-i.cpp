class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        vector<int> result;
        for(int i=0;i<n;i++) {
            unordered_set<int> st;
            for(int len=1;i+len-1<n;len++) {
                st.insert(nums[i + len - 1]);
                result.push_back(st.size());
            }
        }
        int ans = 0;
        for(int i=0;i<result.size();i++) ans += result[i] * result[i];
        return ans;
    }
};