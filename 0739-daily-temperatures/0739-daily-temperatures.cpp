class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> ans;
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) st.pop();
            if(!st.empty()) ans.push_back(st.top() - i);
            else ans.push_back(0);
            st.push(i);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};