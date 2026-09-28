class Solution {
public:
    int maxDepth(string s) {
        stack<char> st;
        int ans = 0;
        for(char c : s) {
            if(c == '(') {
                st.push(c);
            }
            else if(c == ')') {
                if(st.top() == '(') {
                    int size = st.size();
                    ans = max(ans, size);
                    st.pop();
                }
            }
            else continue;
        }
        return ans;
    }
};