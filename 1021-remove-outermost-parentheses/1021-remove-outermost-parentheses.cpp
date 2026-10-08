class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.size();
        stack<char> st;
        vector<int> index;
        for(int i=0;i<n;i++) {
            if(s[i] == '(') {
                if(st.empty()) index.push_back(i);
                st.push(s[i]);
            }
            else if(s[i] == ')') {
                if(st.size() == 1) {
                    st.pop();
                    index.push_back(i);
                }
                else st.pop();
            }
        }
        string ans;
        int j = 0;
        for(int i=0;i<n;i++) {
            if(index[j] == i) {
                j++;
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};