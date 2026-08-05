class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);
        for(auto &i : invocations) {
            int u = i[0];
            int v = i[1];
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(k);
        visited[k] = true;
        while(!q.empty()) {
            int u = q.front();
            q.pop();
            for(int v : adj[u]) {
                if(!visited[v]) {
                    visited[v] = true;
                    q.push(v);
                }
            }
        }
        bool canRemove = true;
        for(auto &i : invocations) {
            int u = i[0];
            int v = i[1];
            if(!visited[u] && visited[v]) {
                canRemove = false;
                break;
            }
        }
        vector<int> ans;
        if(canRemove) {
            for(int i=0;i<n;i++) {
                if(!visited[i]) ans.push_back(i);
            }
        }
        else {
            for(int i=0;i<n;i++) ans.push_back(i);
        }
        return ans;
    }
};