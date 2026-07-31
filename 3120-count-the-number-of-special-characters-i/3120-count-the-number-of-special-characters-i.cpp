class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char, int> freq;
        for(char c : word) {
            freq[c]++;
        }
        int count = 0;
        for(char c='a';c<='z';c++) {
            if(freq.count(c) && freq.count(c - 32)) {
                count++;
            }
        }
        return count;
    }
};