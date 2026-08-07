class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        for(int x : nums) {
            sum += x;
        }
        int i = 0;
        int curr = 0;
        while(i < nums.size()) {
            sum -= nums[i];
            if(curr == sum) {
                return i;
            }
            curr += nums[i];
            i++;
        }
        return -1;
    }
};