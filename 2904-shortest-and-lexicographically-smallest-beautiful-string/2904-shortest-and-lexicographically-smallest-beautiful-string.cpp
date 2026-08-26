class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<int> map(n, -1);
        for(int i=0;i<n;i++) {
            int j = i;
            int count = k;
            while(j < n && count > 0) {
                if(s[j] == '1') {
                    count--;
                    if(count == 0) break;
                }
                j++;
            }
            if(count == 0) map[i] = j;
        }
        int len = INT_MAX;
        int bestStart = -1;
        for(int i=0;i<n;i++) {
            if(map[i] == -1) continue;
            int curr = map[i] - i + 1;
            if(curr < len) {
                len = curr;
                bestStart = i;
            }
            else if(curr == len) {
                if(s.compare(i, len, s, bestStart, len) < 0) {
                    bestStart = i;
                }
            }
        }
        if(bestStart == -1) return "";
        return s.substr(bestStart, len);
    }
};