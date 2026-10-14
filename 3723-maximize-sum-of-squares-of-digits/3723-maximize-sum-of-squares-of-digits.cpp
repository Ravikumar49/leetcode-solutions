class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(num * 9 < sum) return ans;
        while(num > 1 && sum >= 9) {
            ans += '9';
            num--;
            sum -= 9;
        }
        if(num > 1 && sum <= 9) {
            ans += to_string(sum);
            sum = 0;
            num--;
            while(num > 0) {
                ans += '0';
                num--;
            }
        }
        if(num == 1 && sum <= 9) ans += to_string(sum);
        return ans;
    }
};