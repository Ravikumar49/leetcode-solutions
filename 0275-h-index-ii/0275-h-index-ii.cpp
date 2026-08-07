class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int l = 0, r = citations[n-1];
        int ans = -1;
        while(l <= r) {
            int mid = (l + r)/2;
            int cnt = 0;
            for(int i=0;i<n;i++) {
                if(citations[i] >= mid) cnt++;
            }
            if(cnt >= mid) {
                ans = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        return ans;
    }
};