class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c, int k) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        long long sum = grid[r][c];
        visited[r][c] = true;
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nr >= 0 && nc < n && nc >=0 && !visited[nr][nc] && grid[nr][nc] != 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                    sum += grid[nr][nc];
                }
            }
        }
        return sum%k == 0;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        long long count = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j]!= 0 && !visited[i][j]) {
                    if(bfs(grid, visited, i, j, k)) count++;
                }
            }
        }
        return count;
    }
};