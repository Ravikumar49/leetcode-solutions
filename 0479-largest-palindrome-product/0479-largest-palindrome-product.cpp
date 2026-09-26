class Solution {
public:
    long buildPalindrome(int n) {
        string s = to_string(n);
        reverse(s.begin(), s.end());
        return stol(to_string(n) + s);
    }
    int largestPalindrome(int n) {
        if(n == 1) return 9;
        int high = pow(10, n) - 1;
        int low = pow(10, n-1);
        for(int i=high;i>=low;i--) {
            long cand = buildPalindrome(i);
            for(long j=high;j*j>=cand;j--) {
                if(cand%j == 0 && cand / j <= high) return cand % 1337;
            }
        }
        return 0;
    }
};