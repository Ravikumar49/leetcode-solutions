class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int sum = INT_MAX;
        bool found = false;
        for(int i=0;i<nums.size();i++) {
            for(int j=i;j<nums.size();j++) {
                int len = j-i+1;
                int curr = 0;
                if(len>=l && len<=r) {
                    for(int k=i;k<=j;k++) {
                        curr += nums[k];
                    }
                    if(curr > 0) {
                        sum = min(curr, sum);
                        found = true;
                    }
                }
            }
        }
        if(found) {
            return sum;
        }
        return -1;
    }
};