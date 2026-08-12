class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& states, int course) {
        if(states[course] == 1) return true;
        if(states[course] == 2) return false;
        states[course] = 1;
        for(auto c : adj[course]) {
            if(dfs(adj, states, c)) return true;
        }
        states[course] = 2;
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