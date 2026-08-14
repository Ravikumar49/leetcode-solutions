class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n = s.size();
        unordered_map<char, int> freq;
        int j = 0;
        int len = -1;
        for(int i=0;i<n;i++) {
            freq[s[i]]++;
            while(freq[s[i]] > 2) {
                freq[s[j]]--;
                j++;
            }
            len = max(len, i - j + 1);
        }
        return len;
    }
};