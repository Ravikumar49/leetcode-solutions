class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n = img1.size();
        vector<pair<int, int>> ones1;
        vector<pair<int, int>> ones2;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(img1[i][j] == 1) ones1.push_back({i, j});
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                if(img2[i][j] == 1) ones2.push_back({i, j});
            }
        }
        unordered_map<int, int> freq;
        for(int i=0;i<ones1.size();i++) {
            auto [r1, c1] = ones1[i];
            for(int j=0;j<ones2.size();j++) {
                auto [r2, c2] = ones2[j];
                int dr = r2 - r1;
                int dc = c2 - c1;
                int key = (dr + n -1) * (2 * n - 1) - (dc + n - 1);
                freq[key]++;
            }
        }
        int ans = 0;
        for(auto [x, val] : freq) ans = max(val, ans);
        return ans;
    }
};