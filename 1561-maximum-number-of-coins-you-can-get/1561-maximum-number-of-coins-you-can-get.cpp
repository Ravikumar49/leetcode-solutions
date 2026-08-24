class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        n /= 3;
        sort(piles.rbegin(), piles.rend());
        int sum = 0;
        for(int i=1;i<2 * n;i+=2) {
            sum += piles[i];
        }
        return sum;
    }
};