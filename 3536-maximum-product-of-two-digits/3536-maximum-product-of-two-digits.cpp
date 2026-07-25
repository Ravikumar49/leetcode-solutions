class Solution {
public:
    int maxProduct(int n) {
        vector<int> digits;
        while(n > 0) {
            int rem = n % 10;
            digits.push_back(rem);
            n /= 10;
        }
        int len = digits.size();
        if(len < 2) return digits[0] * digits[1];
        sort(digits.begin(), digits.end());
        return digits[len-1] * digits[len-2];
    }
};