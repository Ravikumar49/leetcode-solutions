class Solution {
public:
    unordered_map<int, vector<pair<int, int>>> streets;
    bool canGo(int street, int dr, int dc) {
        for(auto [r, c] : streets[street]) {
            if(r == dr && c == dc) return true;
        }
        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        streets[1] = {{0, 1}, {0, -1}};
        streets[2] = {{1, 0}, {-1, 0}};
        streets[3] = {{0, -1}, {1, 0}};
        streets[4] = {{0, 1}, {1, 0}};
        streets[5] = {{-1, 0}, {0, -1}};
        streets[6] = {{0, 1}, {-1, 0}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()) {
            auto[r, c] = q.front();
            q.pop();
            if(r == m-1 && c == n-1) return true;
            for(auto [dr, dc] : streets[grid[r][c]]) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nr >= 0 && nc < n && nc >= 0 && !visited[nr][nc] && canGo(grid[nr][nc], -dr, -dc)) {
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return false;
    }
};