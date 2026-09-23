class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int m = grid.size();
        int n = grid[0].size();
        vector<int> arr(m*n);
        int index = 0;
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                arr[index++] = grid[i][j];
            }
        }
        int parity = arr[0] % x;
        for(int i=1;i<arr.size();i++) {
            if(arr[i] % x != parity) return -1;
        }
        sort(arr.begin(), arr.end());
        int size = arr.size();
        int median = arr[size/2];
        int steps = 0;
        for(int i=0;i<size;i++) {
            steps += abs(arr[i] - median) / x;
        }
        return steps;
    }
};