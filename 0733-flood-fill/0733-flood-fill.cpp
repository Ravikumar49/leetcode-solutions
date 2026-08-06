class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0, -1}, {-1, 0}};
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.push({sr, sc});
        visited[sr][sc] = true;
        int curr = image[sr][sc];
        image[sr][sc] = color;
        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();
            for(auto [dr, dc] : dir) {
                int nr = r + dr;
                int nc = c + dc;
                if(nr>=0 && nr<m && nc>=0 && nc<n && !visited[nr][nc] && image[nr][nc] == curr) {
                    image[nr][nc] = color;
                    q.push({nr, nc});
                    visited[nr][nc] = true;
                }
            }
        }
        return image;
    }
};