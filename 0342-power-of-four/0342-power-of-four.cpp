class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n == 1 || n == 4) return true;
        while(n > 4) {
            if((n & n-1) != 0) return false;
            n >>= 2;
            if(n == 4) return true;
        }
        return false;
    }
};