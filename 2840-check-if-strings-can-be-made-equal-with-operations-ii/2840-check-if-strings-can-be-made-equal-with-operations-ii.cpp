class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> evenCount(26, 0);
        vector<int> oddCount(26, 0);
        for(int i=0;i<n;i++) {
            if(i%2 == 0) evenCount[s1[i] - 'a']++;
            else oddCount[s1[i]  - 'a']++;
        }
        vector<int> resEvenCount(26, 0);
        vector<int> resOddCount(26, 0);
        for(int i=0;i<n;i++) {
            if(i%2 == 0) resEvenCount[s2[i] - 'a']++;
            else resOddCount[s2[i] - 'a']++;
        }
        for(int i=0;i<26;i++) {
            if((evenCount[i] != resEvenCount[i]) || (oddCount[i] != resOddCount[i])) return false;
        }
        return true;
    }
};