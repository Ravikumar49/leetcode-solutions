class Solution {
public:
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int maxDepth = INT_MIN;
        stack<pair<int, int>> st;
        vector<bool> visited(n+1, false);
        st.push({1, 0});
        while(!st.empty()) {
            auto [node, depth] = st.top();
            st.pop();
            if(visited[node]) continue;
            visited[node] = true;
            maxDepth = max(maxDepth, depth);
            for(auto &nei : adj[node]) {
                if(!visited[nei]) {
                    st.push({nei, depth+1});
                }
            }
        }
        const long long MOD = 1000000007;
        long long ans = 1;
        for(int i=0;i<maxDepth-1;i++) {
            ans = (ans * 2) % MOD;
        }
        return ans;
    }
};