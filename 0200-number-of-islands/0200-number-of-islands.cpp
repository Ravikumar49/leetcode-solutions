class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    q.push({i, j});
                    count++;
                    while(!q.empty()) {
                        auto [r, c] = q.front();
                        visited[r][c] = true;
                        q.pop();
                        for(auto [dr, dc] : dir) {
                            int nr = r + dr;
                            int nc = c + dc;
                            if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == '1') {
                                visited[nr][nc] = true;
                                q.push({nr, nc});
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};