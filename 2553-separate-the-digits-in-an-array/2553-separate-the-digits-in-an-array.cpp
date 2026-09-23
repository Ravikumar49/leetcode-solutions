class Solution {
public:
    vector<int> add(vector<int>& ans, int val) {
        string num = to_string(val);
        for(int i=0;i<num.size();i++) {
            ans.push_back(num[i] - '0');
        }
        return ans;
    }
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0;i<n;i++) {
            if(nums[i] <= 9) ans.push_back(nums[i]);
            else {
                ans = add(ans, nums[i]);
            }
        }
        return ans;
    }
};