class Solution {
public:
    int product(int n) {
        int prod = 1;
        while(n > 0) {
            int rem = n % 10;
            prod *= rem;
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int i;
        for(i=n;i<=n+10;i++) {
            int prod = product(i);
            if(prod % t == 0) break;
        }
        return i;
    }
};