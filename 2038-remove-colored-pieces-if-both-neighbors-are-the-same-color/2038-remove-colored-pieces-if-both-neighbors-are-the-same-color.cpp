class Solution {
public:
    bool winnerOfGame(string s) {
        int n = s.size();
        int aliceChance = 0;
        int bobChance = 0;
        for(int i=1;i<n-1;i++) {
            if(s[i] == 'A' && s[i] == s[i-1] && s[i] == s[i+1]) aliceChance++;
            else if(s[i] == 'B' && s[i] == s[i-1] && s[i] == s[i+1]) bobChance++;
        }
        if(aliceChance == 0) return false;
        if(aliceChance > bobChance) return true;
        return false;
    }
};