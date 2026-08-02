class Solution {
public:
    int integerReplacement(long long n) {
        int ans = 0;
        while(n != 1) {
            if(n%2 == 0) {
                n /= 2;
            }
            else {
                if(n == 3 || n%4 == 1) {
                    n--;
                }
                else {
                    n++;
                }
            }
            ans++;
        }
        return ans;
    }
};