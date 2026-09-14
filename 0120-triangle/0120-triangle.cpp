class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n);
        for(int j=0;j<triangle[n-1].size();j++) {
            dp[j] = triangle[n-1][j];
        }
        for(int i=n-2;i>=0;i--) {
            for(int j=0;j<triangle[i].size();j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }
        return dp[0];
    }
};