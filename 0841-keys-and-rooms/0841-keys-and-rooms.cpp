class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        visited[0] = true;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int currRoom = q.front();
            visited[currRoom] = true;
            q.pop();
            for(auto r : rooms[currRoom]) {
                if(!visited[r]) {
                    q.push(r);
                    visited[r] = true;
                }
            }
        }
        int isPossible = true;
        for(int i=0;i<n;i++) {
            if(!visited[i]) return false;
        }
        return true;
    }
};