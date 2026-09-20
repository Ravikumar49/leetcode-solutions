class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        int start = 0, end = 0, jumps = 0;
        while(true) {
            int curr = -1;
            for(int i=start;i<=end;i++) {
                curr = max(curr, i + nums[i]);
                if(curr >= n-1) return jumps + 1;
            }
            jumps++;
            start = end+1;
            end = curr;
        }
        return 0;
    }
};