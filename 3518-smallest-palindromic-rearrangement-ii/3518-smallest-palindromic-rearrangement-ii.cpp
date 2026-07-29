class Solution {
public:
    long long nCr(int n, int r, int limit) {
        if(r > n-r) r= n-r;
        long long ans = 1;
        for(int i=1;i<=r;i++) {
            ans = ans * (n-r+i)/i;
            if(ans > limit) return limit + 1;
        }
        return ans;
    }
    long long countWays(unordered_map<char, int>& freq, int k) {
        int total = 0;
        for(auto x : freq) {
            total += x.second;
        }
        long long ways = 1;
        int remaining = total;
        for(auto f : freq) {
            if(f.second == 0) continue;
            long long comb = nCr(remaining, f.second, k);
            if(ways > k/comb) {
                return k+1;
            }
            ways *= comb;
            remaining -= f.second;
        }
        return ways;
    }
    string smallestPalindrome(string s, int k) {
        int n = s.size();
        if(n == 1) return s;
        unordered_map<char, int> freq;
        string middle = "";
        for(char c : s) {
            freq[c]++;
        }
        for(char c='a';c<='z';c++) {
            if(freq[c] %2 != 0) middle = c;
            freq[c] /= 2;
        }
        if(countWays(freq, k) < k) return "";
        string leftHalf = "";
        bool found = false;
        for(int pos=0;pos<n/2;pos++) {
            for(char c='a';c<='z';c++) {
                if(freq[c] == 0) continue;
                freq[c]--;
                long long count = countWays(freq, k);
                if(count < k) {
                    k -= count;
                    freq[c]++;
                }
                else {
                    leftHalf.push_back(c);
                    found = true;
                    break;
                }
            }
        }
        if(!found) return "";
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + middle + rightHalf;
    }
};