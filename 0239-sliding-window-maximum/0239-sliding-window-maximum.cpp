class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        priority_queue<pair<int, int>> pq;
        vector<int> res;
        for(int i=0;i<k;i++) pq.push({nums[i], i});
        res.push_back(pq.top().first);
        for(int i=k;i<n;i++) {
            int left = i - k + 1;
            pq.push({nums[i], i});
            while(!pq.empty() && pq.top().second < left) pq.pop();
            res.push_back(pq.top().first);
        }
        return res;
    }
};