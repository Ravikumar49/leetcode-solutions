class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int bfs(queue<pair<int, int>>& q, vector<vector<int>>& grid, vector<vector<bool>>& visited) {
        int count = 1;
        int m = grid.size();
        int n = grid[0].size();
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            visited[r][c] = true;
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1) {
                    count++;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return count;
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++) {
            if(grid[i][0] == 1) q.push({i, 0});
            if(grid[i][n-1] == 1) q.push({i, n-1});
        }
        for(int j=0;j<n;j++) {
            if(grid[0][j] == 1) q.push({0, j});
            if(grid[m-1][j] == 1) q.push({m-1, j});
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            visited[r][c] = true;
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        int count = 0;
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(grid[i][j] == 1 && !visited[i][j]) {
                    q.push({i, j});
                    count += bfs(q, grid, visited);
                }
            }
        }
        return count;
    }
};