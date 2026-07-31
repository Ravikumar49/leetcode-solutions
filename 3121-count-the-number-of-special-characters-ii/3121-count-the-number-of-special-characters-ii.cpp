class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> lowercase(26, -1);
        vector<int> uppercase(26, INT_MAX);
        for(int i=0;i<word.size();i++) {
            if(word[i] >= 'a' && word[i] <= 'z') {
                lowercase[word[i] - 'a'] = max(lowercase[word[i] - 'a'], i);
            }
            else {
                uppercase[word[i] - 'A'] = min(uppercase[word[i] - 'A'], i);
            }
        }
        int count = 0;
        for(int i=0;i<26;i++) {
            if(lowercase[i] != -1 && uppercase[i] != INT_MAX) {
                if(lowercase[i] < uppercase[i]) {
                    count++;
                }
            }
        }
        return count;
    }
};