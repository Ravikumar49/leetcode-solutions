class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        int pivot = 0;
        for(int i=0;i<n;i++) {
            nums[i] *= nums[i];
            if(nums[i] < nums[pivot]) pivot = i;
        }
        int left = pivot - 1;
        int right = pivot + 1;
        ans.push_back(nums[pivot]);
        while(left >= 0 && right < n) {
            if(nums[left] < nums[right]) ans.push_back(nums[left--]);
            else ans.push_back(nums[right++]);
        }
        while(left >= 0) ans.push_back(nums[left--]);
        while(right < n) ans.push_back(nums[right++]);
        return ans;
    }
};