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
        for(auto hit : hits) {
            grid[hit[0]][hit[1]] = 0;
        }
        parent.resize(m*n + 1);
        sz.resize(m*n + 1);
        for(int i=0;i<m*n+1;i++) {
            parent[i] = i;
            sz[i] = 1;
        }
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(grid[i][j] == 0) continue;
                int current = i * n + j;
                if(i == 0) unite(current, m*n);
                if(i+1 < m && grid[i+1][j] == 1) unite(current, (i+1) * n + j);
                if(j+1 < n && grid[i][j+1] == 1) unite(current, i * n + (j + 1));
            }
        }
        vector<int> res(hits.size());
        vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for(int i=hits.size()-1;i>=0;i--) {
            int r = hits[i][0];
            int c = hits[i][1];
            if(original[r][c] == 0 || grid[r][c] == 1) {
                res[i] = 0;
                continue;
            }
            int before = sz[find(m*n)];
            grid[r][c] = 1;
            int current = r * n + c;
            if(r == 0) unite(current, m*n);
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr < m && nr >= 0 && nc < n && nc >= 0 && grid[nr][nc] == 1) unite(current, nr * n + nc);
            }
            int after = sz[find(m*n)];
            res[i] = max(0, after - before - 1);
        }
        return res;
    }
};