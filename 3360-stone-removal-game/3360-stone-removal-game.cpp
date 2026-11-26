class Solution {
public:
    bool canAliceWin(int n) {
        if (n < 10) return false;
        int remove = 9;
        n -= 10;
        bool AliceTurn = false;
        while(n >= remove) {
            n -= remove;
            remove--;
            if(AliceTurn) AliceTurn = false;
            else AliceTurn = true;
        }
        if(!AliceTurn) return true;
        return false;
    }
};