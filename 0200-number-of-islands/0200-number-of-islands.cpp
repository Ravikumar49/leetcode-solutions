class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == '1' && !visited[i][j]) {
                    count++;
                    q.push({i, j});
                    while(!q.empty()) {
                        auto[r, c] = q.front();
                        q.pop();
                        visited[r][c] = true;
                        for(auto [dr, dc] : dir) {
                            int nr = r + dr;
                            int nc = c + dc;
                            if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == '1') {
                                q.push({nr, nc});
                                visited[nr][nc] = true;
                            }
                        }
                    }
                }
            }
        }
        return count;
    }
};