class Solution {
public:
    bool isSafe(vector<string>& board, int row, int col) {
        for(int r=0;r<row;r++) {
            for(int c=0;c<board.size();c++) {
                if(board[r][c] == 'Q') {
                    int rowDiff = abs(row - r);
                    int colDiff = abs(col - c);
                    if(rowDiff == colDiff) return false;
                }
            }
        }
        return true;
    }
    void backtrack(int row, int n, vector<bool>& visited, vector<string>& board, int& count) {
        if(row == n) {
            count++;
            return;
        }
        for(int col=0;col<n;col++) {
            if(!visited[col] && isSafe(board, row, col)) {
                board[row][col] = 'Q';
                visited[col] = true;
                backtrack(row+1, n, visited, board, count);
                visited[col] = false;
                board[row][col] = '.';
            }
        }
    }
    int totalNQueens(int n) {
        int count = 0;
        vector<string> board(n, string(n, '.'));
        vector<bool> visited(n, false);
        backtrack(0, n, visited, board, count);
        return count;
    }
};