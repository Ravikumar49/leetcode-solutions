class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int ans = 0;
        int i = 0;
        while(i < n) {
            int j = i;
            while(j+1 < n && timeSeries[j+1] <= timeSeries[j] + duration - 1) j++;
            ans += timeSeries[j] - timeSeries[i] + duration;
            i = j;
            i++;
        }
        return ans;
    }
};