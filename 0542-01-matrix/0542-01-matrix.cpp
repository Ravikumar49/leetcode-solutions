class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> dp(m, vector<int>(n, INT_MAX));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(mat[i][j] == 0) {
                    q.push({i, j});
                    dp[i][j] = 0;
                }
            }
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nc < n && nr >=0 && nc >= 0 && dp[r][c] + 1 < dp[nr][nc]) {
                    dp[nr][nc] = 1 + dp[r][c];
                    q.push({nr, nc});
                }
            }
        }
        return dp;
    }
};