class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) {
            return 0;
        }
        unordered_map<char, int> freq;
        int j = 0, len = INT_MIN;
        for(int i=0;i<s.size();i++) {
            if(freq.find(s[i]) != freq.end() && freq[s[i]] >= j) {
                j = freq[s[i]] + 1;
            }
            len = max(len, i-j+1);
            freq[s[i]] = i;
        }
        return len;
    }
};