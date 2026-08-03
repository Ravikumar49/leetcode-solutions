class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        vector<int> ans;
        int n = temperatures.size();
        for(int i=n-1;i>=0;i--) {
            while(!st.empty() && temperatures[st.top()] <= temperatures[i]) {
                st.pop();
            }
            if(!st.empty()) {
                ans.push_back(st.top() - i);
            }
            else {
                ans.push_back(0);
            }
            st.push(i);
        }
        int i = 0, j = n-1;
        while(i < j) {
            int temp = ans[i];
            ans[i] = ans[j];
            ans[j] = temp;
            i++;
            j--;
        }
        return ans;
    }
};