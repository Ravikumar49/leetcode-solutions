class Solution {
public:
    int countDigitOne(int n) {
        if(n == 0) return 0;
        if(n <= 9) return 1;
        int ans = 0;
        long long factor = 1;
        while(factor <= n) {
            int higher = n / (factor * 10);
            int current = (n / factor) % 10;
            int lower = n % factor;
            if(current < 1) ans += higher * factor;
            else if(current == 1) ans += higher * factor + lower + 1;
            else  if(current > 1) ans += (higher + 1) * factor;
            factor *= 10;
        }
        return ans;
    }
};