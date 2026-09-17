class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while(n > 0) {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int sumOfSquare(int n) {
        int sum = 0;
        while(n > 0) {
            int rem = n % 10;
            sum += rem * rem;
            n /= 10;
        }
        return sum;
    }
    bool checkGoodInteger(int n) {
        int digitSum = sumOfDigits(n);
        int squareSum = sumOfSquare(n);
        return squareSum - digitSum >= 50;
    }
};