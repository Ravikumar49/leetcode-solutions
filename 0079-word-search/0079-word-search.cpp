class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    bool dfs(vector<vector<char>>& grid, string word, int r, int c, vector<vector<bool>>& visited, int j) {
        if(j == word.size()) return true;
        int m = grid.size();
        int n = grid[0].size();
        visited[r][c] = true;
        for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && grid[nr][nc] == word[j]) {
                    visited[nr][nc] = true;
                    if(dfs(grid, word, nr, nc, visited, j+1)) {
                        return true;
                    }
                    else {
                        visited[nr][nc] = false;
                    }
                }
        }
        visited[r][c] = false;
        return false;
    }
    bool exist(vector<vector<char>>& grid, string word) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == word[0]) {
                    bool isPossible = dfs(grid, word, i, j, visited, 1);
                    if(isPossible) return true;
                }
            }
        }
        return false;
    }
};