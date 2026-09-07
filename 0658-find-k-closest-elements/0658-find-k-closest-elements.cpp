class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        for(int num : arr) {
            if(pq.size() < k) pq.push({abs(num - x), num});
            else {
                auto [worstDiff, worstNum] = pq.top();
                int currDiff = abs(num - x);
                if(currDiff < worstDiff|| currDiff == worstDiff && num < worstNum) {
                    pq.pop();
                    pq.push({currDiff, num});
                }
            }
        }
        vector<int> res;
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        sort(res.begin(), res.end());
        return res;
    }
};