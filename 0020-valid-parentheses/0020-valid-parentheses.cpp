class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        int n = s.size();
        if(n == 1) return false;
        for(int i=0;i<n;i++) {
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                st.push(s[i]);
            }
            else if(s[i] == ')' || s[i] == ']' || s[i] == '}') {
                if(st.empty()) return false;
                else if((st.top() == '(' && s[i] != ')') || (st.top() == '[' && s[i] != ']') || (st.top() == '{' && s[i] != '}')) {
                    return false;
                }
                st.pop();
            }
        }
        if(st.empty()) return true;
        return false;
    }
};