class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(int x : nums) freq[x]++;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for(auto [n, f] : freq) {
            if(pq.size() < k) pq.push({f ,n});
            else if(f > pq.top().first) {
                pq.pop();
                pq.push({f, n});
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            auto [f, n] = pq.top();
            res.push_back(n);
            pq.pop();
        }
        return res;
    }
};