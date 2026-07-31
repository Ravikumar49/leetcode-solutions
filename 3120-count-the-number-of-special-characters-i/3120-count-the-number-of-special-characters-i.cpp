class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char> s(word.begin(), word.end());
        int count = 0;
        for(char c='a';c<='z';c++) {
            if(s.count(c) && s.count(c - 'a' + 'A')) {
                count++;
            }
        }
        return count;
    }
};