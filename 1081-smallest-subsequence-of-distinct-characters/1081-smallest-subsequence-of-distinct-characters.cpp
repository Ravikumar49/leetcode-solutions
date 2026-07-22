class Solution {
public:
    string smallestSubsequence(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        unordered_set<char> visited;
        for(int i=0;i<n;i++) {
            freq[s[i]] = i;
        }
        stack<char> st;
        for(int i=0;i<n;i++) {
            if(visited.find(s[i]) != visited.end()) continue;

            while(!st.empty() && s[i] < st.top() && i < freq[st.top()]) {
                visited.erase(st.top());
                st.pop();
            }

            visited.insert(s[i]);
            st.push(s[i]);
        }

        string res = "";
        while(!st.empty()) {
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};