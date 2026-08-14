class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, int digit) {
        int startRow = (row/3) * 3;
        int startCol = (col/3) * 3;
        for(int r=startRow;r<startRow+3;r++) {
            for(int c=startCol;c<startCol+3;c++) {
                if(board[r][c] == '0' + digit) return false;
            }
        }
        for(int i=0;i<9;i++) {
            if(board[row][i] == '0' + digit) return false;
            if(board[i][col] == '0' + digit) return false;
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board) {
        bool foundEmpty = false;
        int row, col;
        for(int i=0;i<9;i++) {
            for(int j=0;j<9;j++) {
                if(board[i][j] == '.') {
                    foundEmpty = true;
                    row = i;
                    col = j;
                    break;
                }
            }
            if(foundEmpty) break;
        }
        if(!foundEmpty) return true;
        for(int digit=1;digit<=9;digit++) {
            if(isValid(board, row, col, digit)) {
                board[row][col] = '0' + digit;
                if(backtrack(board)) return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board);
    }
};