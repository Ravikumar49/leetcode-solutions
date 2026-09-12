class Solution {
public:
    bool dfs(vector<int>& states, vector<vector<int>>& adj, int course) {
        if(states[course] == 1) return true;
        if(states[course] == 2) return false;
        states[course] = 1;
        for(int c : adj[course]) {
            if(dfs(states, adj, c)) return true;
        }
        states[course] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> states(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[b].push_back(a);
        }
        for(int i=0;i<numCourses;i++) {
            if(dfs(states, adj, i)) return false;
        }
        return true;
    }
};