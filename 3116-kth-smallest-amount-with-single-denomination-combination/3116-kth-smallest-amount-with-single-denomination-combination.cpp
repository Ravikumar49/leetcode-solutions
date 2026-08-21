class Solution {
public:
    long long count(vector<int>& coins, long long x) {
        long long c = 0;
        for(int mask=1;mask<(1<<coins.size());mask++) {
            long long lc = 1;
            int selected = 0;
            for(int j=0;j<coins.size();j++) {
                if(mask & (1 << j)) {
                    selected++;
                    lc = lcm(lc, (long long)coins[j]);
                }
            }
            long long contribution = x/lc;
            if(selected % 2 == 1) c += contribution;
            else c -= contribution;
        }
        return c;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        long long lo = *min_element(coins.begin(), coins.end());
        long long hi = k * lo;
        while(lo < hi) {
            long long mid = lo + (hi - lo)/2;
            if(count(coins, mid) >= k) {
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};