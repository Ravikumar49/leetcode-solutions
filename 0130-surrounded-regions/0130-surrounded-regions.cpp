class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int r, int c) {
        int m = board.size();
        int n = board[0].size();
        for(auto [dr, dc] : dir) {
            int nr = r + dr;
            int nc = c + dc;
            if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && board[nr][nc] == 'O') {
                visited[nr][nc] = true;
                dfs(board, visited, nr, nc);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int j=0;j<n;j++) {
            if(board[0][j] == 'O') {
                visited[0][j] = true;
                dfs(board, visited, 0, j);
            }
            if(board[m-1][j] == 'O') {
                visited[m-1][j] = true;
                dfs(board, visited, m-1, j);
            }
        }
        for(int i=0;i<m;i++) {
            if(board[i][0] == 'O') {
                visited[i][0] = true;
                dfs(board, visited, i, 0);
            }
            if(board[i][n-1] == 'O') {
                visited[i][n-1] = true;
                dfs(board, visited, i, n-1);
            }
        }
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};