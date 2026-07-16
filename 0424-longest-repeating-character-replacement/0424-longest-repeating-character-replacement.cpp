class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int len = 0;
        int j = 0;
        int maxRepeated = 0;
        unordered_map<char, int> freq;
        for(int i=0;i<n;i++) {
            freq[s[i]]++;
            maxRepeated = max(maxRepeated, freq[s[i]]);
            while((i - j + 1 - maxRepeated) > k) {
                freq[s[j]]--;
                j++;
            }
            len = max(len, i-j+1);
        }
        return len;
    }
};