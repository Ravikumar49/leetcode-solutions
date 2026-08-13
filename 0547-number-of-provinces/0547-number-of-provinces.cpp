class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n + 1);
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(i != j && isConnected[i][j] == 1) {
                    adj[i+1].push_back(j+1);
                }
            }
        }
        int count = 0;
        queue<int> q;
        vector<bool> visited(n+1, false);
        for(int i=1;i<=n;i++) {
            if(!visited[i]) {
                q.push(i);
                count++;
                while(!q.empty()) {
                    int curr = q.front();
                    q.pop();
                    for(auto &e : adj[curr]) {
                        if(!visited[e]) {
                            q.push(e);
                            visited[e] = true;
                        }
                    }
                }
            }
        }
        return count;
    }
};