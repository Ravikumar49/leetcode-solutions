class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if (n == 1) return s;
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }
        string leftHalf = "";
        string middle = "";
        for(char c='a';c<='z';c++) {
            if(freq[c - 'a'] > 0) {
                if(freq[c - 'a'] % 2 != 0) middle = c;
                leftHalf.append(freq[c - 'a']/2, c);
            }
        }
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + middle + rightHalf;
    }
};