class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int> copy = nums;
        sort(copy.begin(), copy.end());
        vector<int> indexes;
        for(int i=0;i<n;i++) {
            if(copy[0] == nums[i]) {
                indexes.push_back(i);
            }
        }
        bool flag = true;
        for(int i=0;i<indexes.size();i++) {
            int index = indexes[i];
            flag = true;
            for(int j=0;j<n;j++) {
                if(copy[j] != nums[(index + j) % n]) {
                    flag = false;
                }
                if(!flag) break;
            }
            if(flag) return flag;
        }
        return false;
    }
};