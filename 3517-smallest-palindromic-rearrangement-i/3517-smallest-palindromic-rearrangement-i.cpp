class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        if(n == 1) return s;
        unordered_map<char, int> freq(26);
        for(auto c : s) {
            freq[c]++;
        }
        string leftHalf = "";
        string middle = "";
        for(char c='a';c<='z';c++) {
            if(freq.find(c) != freq.end()) {
                if(freq[c]%2 != 0) middle = c;
                leftHalf.append(freq[c]/2, c);
            }
        }
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + middle + rightHalf;
    }
};