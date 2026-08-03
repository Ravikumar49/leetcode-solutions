class Solution {
public:
    int arrangeCoins(int n) {
        int i = 1;
        while(n - i >= 0) {
            n -= i;
            //cout << n << ":" << i << endl;
            i++;
        }
        return n - i == 0 ? i : i-1;
    }
};