class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool dfs(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int r, int c, int j) {
        if(j == -1) return true;
        int m = board.size();
        int n = board[0].size();
        visited[r][c] = true;
        for(auto [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && board[nr][nc] == word[j]) {
                visited[nr][nc] = true;
                if(dfs(board, word, visited, nr, nc, j-1)) {
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
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(board[i][j] == word.back()) {
                    bool isPossible = dfs(board, word, visited, i, j, word.size() - 2);
                    if(isPossible) return true;
                }
            }
        }
        return false;
    }
};