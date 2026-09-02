class Solution {
public:
    bool dfs(vector<vector<int>>& adj, int course, vector<int>& states) {
        if(states[course] == 1) return true;
        if(states[course] == 2) return false;
        states[course] = 1;
        for(int c : adj[course]) {
            if(dfs(adj, c, states)) return true;
        }
        states[course] = 2;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> states(numCourses, 0);
        vector<vector<int>> adj(numCourses + 1);
        for(auto e : prerequisites) {
            int a = e[0];
            int b = e[1];
            adj[a].push_back(b);
        }
        for(int i=0;i<numCourses;i++) {
            if(dfs(adj, i, states)) return false;
        }
        return true;
    }
};