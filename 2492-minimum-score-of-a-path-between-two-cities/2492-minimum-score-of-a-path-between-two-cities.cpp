class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &e : roads) {
            int u = e[0];
            int v = e[1];
            int cost = e[2];
            adj[u].push_back({v, cost});
            adj[v].push_back({u, cost});
        }
        queue<int> q;
        vector<bool> visited(n+1, false);
        int ans = INT_MAX;
        q.push(1);
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