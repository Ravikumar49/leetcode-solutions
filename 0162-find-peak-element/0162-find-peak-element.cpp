class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int start = 1;
        int end = nums.size() - 2;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1]) return mid;
            if(nums[mid] > nums[mid - 1] && nums[mid] < nums[mid + 1]) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }
        int n = nums.size();
        if(n != 1 && nums[0] > nums[1]) return 0;
        else if(n != 1 && nums[n-1] > nums[n-2]) return n-1;
        return 0;
    }
};