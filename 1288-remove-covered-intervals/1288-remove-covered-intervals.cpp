class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<pair<int, int>> arr(n);
        for(int i=0;i<n;i++) {
            arr[i].first = intervals[i][0];
            arr[i].second = intervals[i][1];
        }
        int count = 0;
        sort(arr.begin(), arr.end(), [](const auto& a, const auto& b) {
            if(a.first != b.first) {
                return a.first < b.first;
            }
            return a.second > b.second;
        });
        int maxRightSeen = arr[0].second;
        for(int i=1;i<n;i++) {
            if(arr[i].second <= maxRightSeen) {
                count++;
            }
            else {
                maxRightSeen = arr[i].second;
            }
        }
        return n - count;
    }
};