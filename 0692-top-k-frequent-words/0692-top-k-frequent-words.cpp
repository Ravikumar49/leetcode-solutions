class Solution {
public:
    struct Compare {
        bool operator()(const pair<int, string>& a, const pair<int, string>& b) {
            if(a.first != b.first) return a.first > b.first;
            return a.second < b.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> freq;
        for(string str : words) freq[str]++;
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        for(auto [str, f] : freq) {
            if(pq.size() < k) pq.push({f, str});
            else if(f > pq.top().first || (f == pq.top().first && str < pq.top().second)) {
                pq.pop();
                pq.push({f, str});
            }
        }
        vector<string> res;
        while(!pq.empty()) {
            auto [f, str] = pq.top();
            res.push_back(str);
            pq.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};