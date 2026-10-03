class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        stack<int> st;
        for(int i=0;i<n;i++) {
            int curr = asteroids[i];
            bool alive = true;
            
            while(!st.empty() && st.top() > 0 && curr < 0) {
                if(abs(st.top()) < abs(curr)) {
                    st.pop();
                }
                else if(abs(st.top()) == abs(curr)) {
                    st.pop();
                    alive = false;
                    break;
                }
                else {
                    alive = false;
                    break;
                }
            }
            if(alive) st.push(curr);    
        }
        vector<int> ans;
        while(!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};