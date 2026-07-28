class Solution {
public:
    string sortVowels(string s) {
        vector<char> vowel;
        for(char c : s) {
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                vowel.push_back(c);
            }
        }
        sort(vowel.begin(), vowel.end());
        string t = "";
        int index = 0;
        for(char c : s) {
            if(c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
               c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
                t.push_back(vowel[index]);
                index++;
            }
            else {
                t.push_back(c);
            }
        }
        return t;
    }
};