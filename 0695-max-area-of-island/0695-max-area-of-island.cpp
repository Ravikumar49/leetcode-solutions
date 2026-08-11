class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int maxCount = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    int count = 1;
                    q.push({i, j});
                    visited[i][j] = true;
                    while(!q.empty()) {
                        auto [r, c] = q.front();
                        q.pop();
                        for(auto [dr, dc] : dir) {
                            int nr = r + dr;
                            int nc = c + dc;
                            if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1) {
                                count++;
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                    maxCount = max(maxCount, count);
                }
            }
        }
        return maxCount;
    }
};