class Solution {
public:
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int r = 0, c = 0;
        while(true) {
            char ch = grid[r][c];
            visited[r][c] = true;
            int nr = r;
            int nc = c;
            if (ch == 'L') nc--;
            else if (ch == 'R') nc++;
            else if (ch == 'U') nr--;
            else nr++;
            if(nr >= m || nr < 0 || nc >= n || nc < 0) return {r, c};
            else if(visited[nr][nc]) return {r, c};
            visited[nr][nc] = true;
            r = nr;
            c = nc;
        }
        return {};
    }
};