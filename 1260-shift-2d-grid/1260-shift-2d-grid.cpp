class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> flat(m * n);
        vector<int> shifted(m * n);
        int index = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                flat[index++] = grid[i][j];
            }
        }
        int N = m * n;
        for(int i=0;i<N;i++) {
            shifted[(i + k) % N] = flat[i];
        }
        index = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                grid[i][j] = shifted[index++];
            }
        }
        return grid;
    }
};