class Solution {
public:
    vector<int> digitCount(int n) {
        vector<int> freq(10, 0);
        while(n > 0) {
            int rem = n % 10;
            freq[rem]++;
            n /= 10;
        }
        return freq;
    }
    bool isDigitorialPermutation(int n) {
        unordered_map<int, int> factorial;
        factorial[0] = 1;
        factorial[1] = 1;
        factorial[2] = 2;
        factorial[3] = 6;
        factorial[4] = 24;
        factorial[5] = 120;
        factorial[6] = 720;
        factorial[7] = 5040;
        factorial[8] = 40320;
        factorial[9] = 362880;
        int sum = 0;
        int num = n;
        while(n > 0) {
            int rem = n % 10;
            sum += factorial[rem];
            n /= 10;
        }
        if(sum == num) return true;
        vector<int> freq1 = digitCount(sum);
        vector<int> freq2 = digitCount(num);
        for(int i=0;i<=9;i++) if(freq1[i] != freq2[i]) return false;
        return true;
    }
};