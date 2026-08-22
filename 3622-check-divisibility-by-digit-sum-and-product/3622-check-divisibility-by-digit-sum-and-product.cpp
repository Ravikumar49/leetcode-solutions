class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int original = n;
        while(n > 0) {
            int rem = n%10;
            sum += rem;
            product *= rem;
            n /= 10;
        }
        int newSum = sum + product;
        if(original % newSum == 0) return true;
        return false;
    }
};