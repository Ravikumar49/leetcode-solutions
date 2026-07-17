class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        for(int i=index;i<nums.size();i++) {
            if(nums[i] != nums[index-1]) {
                int t = nums[index];
                nums[index] = nums[i];
                nums[i] = t;
                index++;
            }
        }
        return index;
    }
};