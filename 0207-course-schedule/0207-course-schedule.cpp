class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& states, int courses) {
        if(states[courses] == 1) return true;
        if(states[courses] == 2) return false;
        states[courses] = 1;
        for(int c : adj[courses]) {
            if(dfs(adj, states, c)) return true;
        }
        states[courses] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> states(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[a].push_back(b);
        }
        for(int i=0;i<numCourses;i++) {
            if(dfs(adj, states, i)) return false;
        }
        return true;
    }
};