class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int amount = 0;
        sort(cost.rbegin(), cost.rend());
        for(int i=0;i<cost.size();i++) {
            if(i%3 != 2) {
                amount += cost[i];
            }
        }
        return amount;
    }
};