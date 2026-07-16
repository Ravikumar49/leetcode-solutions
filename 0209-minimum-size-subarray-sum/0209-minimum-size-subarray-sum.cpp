class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;
        int len = INT_MAX;
        while(i < n) {
            sum += nums[i];
            while(j < n && sum >= target) {
                if(sum >= target) {
                    len = min(len, i - j + 1);
                }
                sum -= nums[j];
                j++;
                cout << len << endl;
            }
            i++;
        }
        return len == INT_MAX ? 0 : len;
    }
};