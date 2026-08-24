class Solution {
public:
    bool canIWinRec(int mask, vector<int>& memo, int currentTotal, int maxChoice, int desiredTotal) {
        if(memo[mask] != -1) return memo[mask];
        for(int x=1;x<=maxChoice;x++) {
            if(mask & (1<<x)) continue;
            if(currentTotal + x >= desiredTotal) {
                memo[mask] = 1;
                return true;   
            }
            else {
                int newMask = mask | (1 << x);
                if(!canIWinRec(newMask, memo, currentTotal + x, maxChoice, desiredTotal)) {
                    memo[mask] = 1;
                    return true;
                }
            }
        }
        memo[mask] = 0;
        return false;
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        if(desiredTotal <= maxChoosableInteger) return true;
        int n = maxChoosableInteger;
        if((n * (n+1)) < 2 * desiredTotal) return false;
        vector<int> memo(2 << maxChoosableInteger, -1);
        int mask = 0;
        return canIWinRec(mask, memo, 0, maxChoosableInteger, desiredTotal);
    }
};