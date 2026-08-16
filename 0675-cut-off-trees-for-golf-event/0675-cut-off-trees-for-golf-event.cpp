class Solution {
public:
    vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int bfs(vector<vector<int>>& forest, int target_r, int target_c, queue<pair<int, int>>& q) {
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int steps = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                auto [r, c] = q.front();
                q.pop();
                if(r == target_r && c == target_c) {
                    forest[r][c] = 1;
                    return steps;
                }
                for(auto [dr, dc] : dir) {
                    int nr = r + dr;
                    int nc = c + dc;
                    if(nr < m && nc < n && nr >= 0 && nc >= 0 && !visited[nr][nc] && forest[nr][nc] > 0) {
                        q.push({nr, nc});
                        visited[nr][nc] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        int m = forest.size();
        int n = forest[0].size();
        vector<tuple<int, int, int>> trees;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                if(forest[i][j] > 1) {
                    trees.push_back({forest[i][j], i, j});
                }
            }
        }
        sort(trees.begin(), trees.end());
        pair<int, int> current = {0, 0};
        int total = 0;
        for(int x=0;x<trees.size();x++) {
            auto [target, target_r, target_c] = trees[x];
            queue<pair<int, int>> q;
            q.push(current);
            int distance = bfs(forest, target_r, target_c, q);
            if(distance == -1) return -1;
            total += distance;
            current = {target_r, target_c};
        }
        return total;
    }
};