class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for(int i=0;i<min(n,k);i++) pq.push({matrix[i][0], i, 0});
        int ans;
        for(int count=0;count<k && !pq.empty();count++) {
            auto [val, i, j] = pq.top();
            pq.pop();
            ans = val;
            if(j + 1 < n) pq.push({matrix[i][j+1], i, j+1});
        }
        return ans;
    }
};