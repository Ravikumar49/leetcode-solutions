class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minTime = INT_MAX;
        for(int i=0;i<n;i++) {
            int landTime = landStartTime[i] + landDuration[i];
            for(int j=0;j<m;j++) {
                int wait = max(landTime, waterStartTime[j]);
                int waterTime = wait + waterDuration[j];
                minTime = min(minTime, waterTime);
            }
        }
        for(int j=0;j<m;j++) {
            int waterTime = waterStartTime[j] + waterDuration[j];
            for(int i=0;i<n;i++) {
                int wait = max(waterTime, landStartTime[i]);
                int landTime = wait + landDuration[i];
                minTime = min(minTime, landTime);
            }
        }
        return minTime;
    }
};