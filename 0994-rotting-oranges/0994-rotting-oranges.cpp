class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<pair<int, int>> q;
        int totalFresh = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 2) q.push({i, j});
                else if(grid[i][j] == 1) totalFresh++;
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int invaded = 0;
        int time = 0;
        while(!q.empty()) {
            int size = q.size();
            bool spread = false;
            for(int i=0;i<size;i++) {
                auto[r, c] = q.front();
                visited[r][c] = true;
                q.pop();
                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr < m && nr >= 0 && nc < n && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == 1) {
                        invaded++;
                        spread = true;
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            if(spread) time++;
        }
        if(invaded == totalFresh) return time;
        return -1;
    }
};