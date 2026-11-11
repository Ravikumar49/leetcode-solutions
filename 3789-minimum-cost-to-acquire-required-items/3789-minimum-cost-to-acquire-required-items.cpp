class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long cost = 0;
        if(need1 == 0 && need2 == 0) return cost;
        long long rate = min(costBoth, cost1 + cost2);
        long long done = min(need1, need2);
        cost = rate * done;
        long long rem1 = 0, rem2 = 0;
        if(done < need1) {
            rem1 = need1 - need2;
        }
        else if(done < need2) {
            rem2 = need2 - need1;
        }
        cost += min(costBoth, cost1) * rem1 + min(costBoth, cost2) * rem2;
        return cost;
    }
};