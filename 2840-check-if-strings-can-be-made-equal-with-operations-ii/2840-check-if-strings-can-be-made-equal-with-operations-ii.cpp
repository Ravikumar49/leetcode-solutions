class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string evenChar, oddChar;
        for(int i=0;i<n;i++) {
            if(i%2 == 0) evenChar.push_back(s1[i]);
            else oddChar.push_back(s1[i]);
        }
        string resEvenChar, resOddChar;
        for(int i=0;i<n;i++) {
            if(i%2 == 0) resEvenChar.push_back(s2[i]);
            else resOddChar.push_back(s2[i]);
        }
        sort(evenChar.begin(), evenChar.end());
        sort(oddChar.begin(), oddChar.end());
        sort(resEvenChar.begin(), resEvenChar.end());
        sort(resOddChar.begin(), resOddChar.end());
        if((evenChar == resEvenChar) && (oddChar == resOddChar)) return true;
        return false;
    }
};