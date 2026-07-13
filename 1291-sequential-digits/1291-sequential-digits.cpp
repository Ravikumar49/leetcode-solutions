class Solution {
public:
    int digit(int n) {
        int count = 0;
        while(n > 0) {
            count++;
            n /= 10;
        }
        return count;
    }
    vector<int> sequentialDigits(int low, int high) {
        int lowLen = digit(low);
        int highLen = digit(high);
        vector<int> ans;
        while(lowLen <= highLen) {
            int length = lowLen;
            int start = 1;
            while(start <= 10 - length) {
                int num = 0;
                int digit = start;
                while(length > 0) {
                    num = num * 10 + digit;
                    digit++;
                    length--;
                }
                if(low <= num && num <= high) ans.push_back(num);
                start++;
                length = lowLen;
            }
            lowLen++;
        }
        return ans;
    }
};