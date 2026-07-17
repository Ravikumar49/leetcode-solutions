class Solution {
public:
    string stackOpr(string str) {
        stack<char> st;
        for(char c : str) {
            if(!st.empty() && c == '#') {
                st.pop();
            }
            else {
                st.push(c);
            }
        }
        string res = "";
        while(!st.empty()) {
            if(st.top() != '#') res += st.top();
            st.pop();
            cout << res << endl;
        }
        return res;
    }
    bool backspaceCompare(string s, string t) {
        s = stackOpr(s);
        t = stackOpr(t);
        return s == t;
    }
};