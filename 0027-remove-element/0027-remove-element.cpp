class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int count = 0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i] != val) {
                int t = nums[i];
                nums[i] = nums[count];
                nums[count] = t;
                count++;
            }
        }
        return count;
    }
};