class Solution {
public:
    long long count(vector<long long>& subsetLCM, vector<int>& parity, long long x) {
        long long c = 0;
        for(int mask=1;mask<subsetLCM.size();mask++) {
            if(subsetLCM[mask] > x) continue;
            long long contribution = x / subsetLCM[mask];
            if(parity[mask]) c+= contribution;
            else c-= contribution;
        }
        return c;
    }
    long long findKthSmallest(vector<int>& coins, int k) {
        int n = coins.size();
        int totalMasks = 1 << n;
        vector<long long> subsetLCM(totalMasks);
        vector<int> parity(totalMasks);

        subsetLCM[0] = 1;
        parity[0] = 0;
        
        for(int mask=1;mask<totalMasks;mask++) {
            int bit = __builtin_ctz(mask);
            int prev = mask & (mask - 1);

            subsetLCM[mask] = lcm(subsetLCM[prev], (long long)coins[bit]);
            parity[mask] = parity[prev] ^ 1;
        }
        long long lo = *min_element(coins.begin(), coins.end()); long long hi = k * lo;
        while(lo < hi) { 
            long long mid = lo + (hi - lo)/2;
            if(count(subsetLCM, parity, mid) >= k) { 
                hi = mid;
            }
            else {
                lo = mid + 1;
            }
        }
        return lo;
    }
};