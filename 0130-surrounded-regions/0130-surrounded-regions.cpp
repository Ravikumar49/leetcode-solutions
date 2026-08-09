class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(board[0][j] == 'O') {
                    q.push({0, j});
                }
                if(board[m-1][j] == 'O') {
                    q.push({m-1, j});
                }
                if(board[i][0] == 'O') {
                    q.push({i, 0});
                }
                if(board[i][n-1] == 'O') {
                    q.push({i, n-1});
                }
            }
        }
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto[r, c] = q.front();
                visited[r][c] = true;
                q.pop();
                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && board[nr][nc] == 'O') {
                        visited[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
        }
        for(int i=1;i<m-1;i++) {
            for(int j=1;j<n-1;j++) {
                if(board[i][j] == 'O' && !visited[i][j]) board[i][j] = 'X';
            }
        }
    }
};