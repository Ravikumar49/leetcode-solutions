class Solution {
public:
    bool bfs(vector<vector<int>>& grid, int t) {
        int n = grid.size();
        if(grid[0][0] > t) return false;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        queue<pair<int, int>> q;
        q.push({0, 0});
        visited[0][0] = true;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto [r, c] = q.front();
                q.pop();
                if(r == n-1 && c == n-1) return true;
                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr < n && nr >= 0 && nc < n && nc >= 0 && !visited[nr][nc] && grid[nr][nc] <= t) {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
        }
        return false;
    }
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int left = 0;
        int right = n * n - 1;
        while(left < right) {
            int mid = left + (right - left) / 2;
            if(bfs(grid, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};