class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        for(int r=0;r<row;r++) {
            for(int c=0;c<board.size();c++) {
                if(board[r][c] == 'Q') {
                    int rowDiff = abs(r - row);
                    int colDiff = abs(c - col);
                    if(rowDiff == colDiff) return false;
                }
            }
        }
        return true;
    }
    void backtrack(int n, int row, vector<bool>& visited, vector<string>& board, vector<vector<string>>& res) {
        if(row == n) {
            res.push_back(board);
            return;
        }
        for(int col=0;col<n;col++) {
            if(!visited[col] && isSafe(board, row, col)) {
                board[row][col] = 'Q';
                visited[col] = true;
                backtrack(n, row+1, visited, board, res);
                board[row][col] = '.';
                visited[col] = false;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> board(n, string(n, '.'));
        vector<bool> visited(n, false);
        backtrack(n, 0, visited, board, res);
        return res;
    }
};