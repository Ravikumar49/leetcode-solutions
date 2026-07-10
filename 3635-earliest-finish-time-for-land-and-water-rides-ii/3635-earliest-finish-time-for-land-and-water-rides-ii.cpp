class Solution {
public:
    int search(vector<pair<int, int>> &ride, int low, int high, int val) {
        if(low == high) {
            return low;
        }
        int mid = (low + high)/2;
        if(ride[mid].first > val) {
            return search(ride, low, mid, val);
        }
        return search(ride, mid+1, high, val);
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size();
        int m = waterStartTime.size();
        vector<pair<int, int>> land(n);
        for(int i=0;i<n;i++) {
            land[i].first = landStartTime[i];
            land[i].second = landDuration[i];
        }
        vector<pair<int, int>> water(m);
        for(int j=0;j<m;j++) {
            water[j].first = waterStartTime[j];
            water[j].second = waterDuration[j];
        }
        sort(land.begin(), land.end());
        sort(water.begin(), water.end());
        vector<int> minLandRide(n);
        minLandRide[n-1] = land[n-1].first + land[n-1].second;
        for(int i=n-2;i>=0;i--) {
            minLandRide[i] = min(minLandRide[i+1], land[i].first + land[i].second);
        }
        vector<int> minLandDuration(n);
        minLandDuration[0] = land[0].second;
        for(int i=1;i<n;i++) {
            minLandDuration[i] = min(minLandDuration[i-1], land[i].second);
        }
        vector<int> minWaterRide(m);
        minWaterRide[m-1] = water[m-1].first + water[m-1].second;
        for(int i=m-2;i>=0;i--) {
            minWaterRide[i] = min(minWaterRide[i+1], water[i].first + water[i].second);
        }
        vector<int> minWaterDuration(m);
        minWaterDuration[0] = water[0].second;
        for(int i=1;i<m;i++) {
            minWaterDuration[i] = min(minWaterDuration[i-1], water[i].second);
        }
        int finalTime = INT_MAX;
        for(int i=0;i<n;i++) {
            int landTime = land[i].first + land[i].second;
            int index = -1;
            int curr;
            if(water[m-1].first > landTime) {
                index = search(water, 0, m-1, landTime);
            }
            if(index == -1) {
                curr = landTime + minWaterDuration[m-1];
            }
            else if(index == 0) {
                curr = minWaterRide[0];
            }
            else {
                curr = min(minWaterRide[index], landTime + minWaterDuration[index-1]);
            }
            finalTime = min(curr, finalTime);
        }
        for(int j=0;j<m;j++) {
            int waterTime = water[j].first + water[j].second;
            int index = -1;
            int curr;
            if(land[n-1].first > waterTime) {
                index = search(land, 0, n-1, waterTime);
            }
            if(index == -1) {
                curr = waterTime + minLandDuration[n-1];
            }
            else if(index == 0) {
                curr = minLandRide[0];
            }
            else {
                curr = min(minLandRide[index], waterTime + minLandDuration[index-1]);
            }
            finalTime = min(curr, finalTime);
        }
        return finalTime;
    }
};