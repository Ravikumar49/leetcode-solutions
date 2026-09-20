class Solution {
public:
    int reverseDegree(string s) {
        vector<int> pos(26);
        int val = 26;
        for(int i=0;i<26;i++) pos[i] = val--;
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++) {
            ans += pos[s[i] - 'a'] * (i+1);
        }
        return ans;
    }
};