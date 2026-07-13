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
        for(int len=lowLen;len<=highLen;len++) {
            for(int start = 1;start<=10 - len;start++) {
                int num = 0;
                for(int d=0;d<len;d++) {
                    num = num * 10 + (start + d);
                }
                if(low <= num && num <= high) ans.push_back(num);
            }
        }
        return ans;
    }
};