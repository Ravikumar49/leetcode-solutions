class Solution {
public:
    int minimumPushes(string word) {
        int ans = 0;
        vector<int> map(26, 0);
        for(char c : word) {
            map[c - 'a']++;
        }
        sort(map.rbegin(), map.rend());
        for(int i=0;i<26;i++) {
            if(map[i] == 0) break;
            ans += (i/8 + 1) * map[i];
        }
        return ans;
    }
};