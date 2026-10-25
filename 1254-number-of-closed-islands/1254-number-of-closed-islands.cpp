class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    void bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({r, c});
        visited[r][c] = true;
        while(!q.empty()) {
            auto[r, c] = q.front();
            q.pop();
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nr >= 0 && nc < n && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;;
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>>q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int j=0;j<n;j++) {
            if(grid[0][j] == 0) q.push({0, j});
            if(grid[m-1][j] == 0) q.push({m-1, j});
        }
        for(int i=0;i<m;i++) {
            if(grid[i][0] == 0) q.push({i, 0});
            if(grid[i][n-1] == 0) q.push({i, n-1});
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            visited[r][c] = true;
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nr >= 0 && nc < n && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 0) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;;
                }
            }
        }
        int count = 0;
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(!visited[i][j] && grid[i][j] == 0) {
                    count++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return count;
    }
};