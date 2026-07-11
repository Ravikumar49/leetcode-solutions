class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for(auto &e : edges) {
            int u = e[0];
            int v = e[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        int ans = 0;
        vector<int> visited(n, false);
        for(int i=0;i<n;i++) {
            if(!visited[i]) {
                int vertices = 0;
                int edgeCount = 0;
                q.push(i);
                visited[i] = true;
                while(!q.empty()) {
                    int u = q.front();
                    q.pop();
                    vertices++;
                    for(int v : adj[u]) {
                        edgeCount++;
                        if(!visited[v]) {
                            visited[v] = true;
                            q.push(v);
                        }
                    }
                }
                if(edgeCount == vertices * (vertices - 1)) ans++;
            }
        }
        return ans;
    }
};