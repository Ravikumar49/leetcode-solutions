class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<int, int>> q;
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool isFound = false;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 1) {
                    isFound = true;
                    q.push({i, j});
                    break;
                }
            }
            if(isFound) break;
        }
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            grid[r][c] = 2;
            visited[r][c] = true;
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < n && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1) {
                    visited[nr][nc] = true;
                    grid[nr][nc] = 2;
                    q.push({nr, nc});
                }
            }
        }
        int distance = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto [r, c] = q.front();
                q.pop();
                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr < n && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 0) {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                    else if(nr < n && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1) {
                        return distance;
                    }
                }
            }
            distance++;
        }
        return 0;
    }
};