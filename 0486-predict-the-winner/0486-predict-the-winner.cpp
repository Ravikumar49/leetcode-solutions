class Solution {
public:
    int maxScore(int i, int j, int turn, vector<int>& nums) {
        if(i == j) return nums[i];
        if(turn == 0) {
            int s1 = nums[i] + maxScore(i+1, j, 1, nums);
            int s2 = nums[j] + maxScore(i, j-1, 1, nums);
            return max(s1, s2);
        }
        else {
            int s1 = maxScore(i+1, j, 0, nums);
            int s2 = maxScore(i, j-1, 0, nums);
            return min(s1, s2);
        }
    }
    bool predictTheWinner(vector<int>& nums) {
        int sum = 0;
        for(int x:nums) {
            sum += x;
        }
        int p1_score = maxScore(0, nums.size()-1, 0, nums);
        int p2_score = sum - p1_score;
        return p1_score>=p2_score;
    }
};