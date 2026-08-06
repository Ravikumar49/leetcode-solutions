class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &r : roads) {
            int u = r[0];
            int v = r[1];
            int cost = r[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        int ans = INT_MAX;
        queue<int> q;
        vector<bool> visited(n+1, false);
        q.push(1);
        visited[1] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(auto [v, cost] : adj[u]) {
                ans = min(ans, cost);
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
};