class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int maxCost = *max_element(costs.begin(), costs.end());
        vector<int> freq(maxCost + 1, 0);

        for(int c : costs) {
            freq[c]++;
        }

        int ans = 0;
        for(int i=0;i<=maxCost;i++) {
            while(freq[i] > 0 && coins >= i) {
                coins -= i;
                ans++;
                freq[i]--;
            }
            if(coins < i) break;
        }
        return ans;
    }
};