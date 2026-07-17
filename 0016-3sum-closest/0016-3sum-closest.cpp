class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int sum = 0, diff = INT_MAX;
        for(int i=0;i<n-2;i++) {
            if(i > 0 && nums[i] == nums[i-1]) continue;
            int j = i+1, k = n-1;
            while(j < k) {
                int curr = nums[i] + nums[j] + nums[k];
                if(abs(target - curr) < diff) {
                    diff = abs(target - curr);
                    sum = curr;
                }
                else if(abs(target - curr) == diff) {
                    sum = max(sum, curr);
                }
                if(curr < target) j++;
                else  k--;
            }
        }
        return sum;
    }
};