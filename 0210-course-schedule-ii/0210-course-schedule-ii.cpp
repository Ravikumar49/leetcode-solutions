class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& states, int course, vector<int>& ans) {
        if(states[course] == 1) return true;
        if(states[course] == 2) return false;
        states[course] = 1;
        for(int c : adj[course]) {
            if(dfs(adj, states, c, ans)) return true;
        }
        ans.push_back(course);
        states[course] = 2;
        return false;
    }
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> states(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(auto &p : prerequisites) {
            int a = p[0];
            int b = p[1];
            adj[a].push_back(b);
        }
        vector<int> ans;
        for(int i=0;i<numCourses;i++) {
            if(dfs(adj, states, i, ans)) return {};
        }
        return ans;
    }
};