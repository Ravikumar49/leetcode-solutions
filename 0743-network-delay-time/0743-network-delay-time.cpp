class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto t : times) {
            int u = t[0];
            int v = t[1];
            int w = t[2];
            adj[u].push_back({v, w});
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> dist(n+1, INT_MAX);
        dist[k] = 0;
        pq.push({0, k});
        while(!pq.empty()) {
            auto [currentDist, current] = pq.top();
            pq.pop();
            if(currentDist > dist[current]) continue;
            for(auto [next, weight] : adj[current]) {
                int newDist = currentDist + weight;
                if(newDist < dist[next]) {
                    dist[next] = newDist;
                    pq.push({newDist, next});
                }
            }
        }
        int ans = -1;
        for(int i=1;i<=n;i++) ans = max(ans, dist[i]);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};