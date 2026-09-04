class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        for(int i=0;i<min(k, (int)nums1.size());i++) pq.push({nums1[i] + nums2[0], i, 0});
        vector<vector<int>> res;
        for(int count=0;count<k && !pq.empty();count++) {
            auto [sum, i, j] = pq.top();
            pq.pop();
            res.push_back({nums1[i], nums2[j]});
            if(j + 1 < nums2.size()) pq.push({nums1[i] + nums2[j + 1], i, j+1});
        }
        return res;
    }
};