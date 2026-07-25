class Solution {
public:
    int myAtoi(string s) {
        int n = s.size();
        long long num = 0;
        int place = 1;
        int index = 0;
        while(index < n && s[index] == ' ') index++;
        if(index == n) return 0;
        int sign = 1;
        if(s[index] == '-') {
            sign = -1;
            index++;
        }
        else if(s[index] == '+') {
            index++;
        }
        while(index < n && isdigit(s[index])) {
            int digit = s[index] - '0';
            num = num * 10 + digit;
            if(sign * num <= INT_MIN) {
                return INT_MIN;
            }
            if(sign * num >= INT_MAX) {
                return INT_MAX;
            }
            index++;
        }
        return sign * num;
    }
};