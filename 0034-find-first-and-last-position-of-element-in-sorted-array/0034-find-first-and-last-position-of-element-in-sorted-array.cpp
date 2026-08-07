class Solution {
public:
    int search(vector<int>& nums, int target, bool isSearchingLeft) {
        int left = 0;
        int right = nums.size() - 1;
        int idx = -1;
        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] > target) {
                right = mid - 1;
            }
            else if(nums[mid] < target) {
                left = mid + 1;
            }
            else {
                idx = mid;
                if(isSearchingLeft) {
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }
        }
        return idx;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res = {-1, -1};
        int n = nums.size();
        if(n == 0) return res;
        int left = search(nums, target, true);
        int right = search(nums, target, false);
        res[0] = left;
        res[1] = right;
        return res;
    }
};