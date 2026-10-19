class Solution {
public:
    int minSelection(vector<vector<int>>& availableIntervals, vector<vector<int>>& targetIntervals) {
        int n = availableIntervals.size();
        int m = targetIntervals.size();

        sort(availableIntervals.begin(), availableIntervals.end());
        sort(targetIntervals.begin(), targetIntervals.end());

        int i = 0, j = 0, maxi = -1, curr = targetIntervals[j][0], ans = 0;
        while(j < m) {
            int pmax = maxi;
            while(i < n && availableIntervals[i][0] <= curr) {
                maxi = max(maxi, availableIntervals[i][1]);
                i++;
            }

            if(pmax == maxi) return -1;
            ans++;

            while(j < m && targetIntervals[j][1] <= maxi) j++;
            if(j == m) return ans;

            if(maxi < targetIntervals[j][0]) curr = targetIntervals[j][0];
            else curr = maxi;
        }
        return ans;
    }
};