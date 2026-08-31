class Solution {
public:
    vector<int> parent;
    vector<int> sz;
    int find(int x) {
        if(parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if(a != b) {
            parent[b] = a;
            sz[a] += sz[b];
        }
    }
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> original = grid;
        for(auto r : hits) {
            int row = r[0];
            int col = r[1];
            grid[row][col] = 0;
        }
        parent.resize(m*n + 1);
        sz.resize(m*n + 1);
        for(int i=0;i<m*n+1;i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        for(int r=0;r<m;r++) {
            for(int c=0;c<n;c++) {
                if(grid[r][c] == 0) continue;
                int current = r * n + c;
                if(r == 0) unite(current, m*n);
                if(r+1<m && grid[r+1][c] == 1) unite(current, (r+1)*n + c);
                if(c+1<n && grid[r][c+1] == 1) unite(current, r * n + (c+1));
            }
        }
        vector<pair<int, int>> dir = {{0,1}, {0, -1}, {1, 0}, {-1, 0}};
        vector<int> res(hits.size());
        for(int i=hits.size()-1;i>=0;i--) {
            int row = hits[i][0];
            int col = hits[i][1];
            if(original[row][col] == 0 || grid[row][col] == 1) {
                res[i] = 0;
                continue;
            }
            int before = sz[find(m*n)];
            grid[row][col] = 1;
            int current = row * n + col;
            if(row == 0) unite(current, m*n);
            for(auto [dr, dc] : dir) {
                int nr = row + dr;
                int nc = col + dc;
                if(nr < m && nr >=0 && nc < n && nc >= 0 && grid[nr][nc] == 1) unite(current, nr*n + nc);
            }
            int after = sz[find(m*n)];
            res[i] = max(0, after - before - 1);
        }
        return res;
    }
};