class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n < 0) return false;
        int MASK = 0;
        for(int i=0;i<=31;i++) {
            if(i%2 == 0) MASK |= 1 << i;
        }
        if((n & n-1) == 0 && (n & MASK) != 0) return true;
        return false;
    }
};