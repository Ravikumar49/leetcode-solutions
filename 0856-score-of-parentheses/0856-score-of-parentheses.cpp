class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.size();
        stack<int> st;
        st.push(0);
        for(int i=0;i<n;i++) {
            if(s[i] == '(') st.push(0);
            else {
                int inside = st.top();
                st.pop();

                if(inside == 0) inside = 1;
                else inside *= 2;

                st.top() += inside;
            }
        }
        return st.top();
    }
};