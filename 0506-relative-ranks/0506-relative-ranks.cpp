class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<score.size();i++) pq.push({score[i], i});
        vector<string> ans(score.size());
        for(int count=0;count<3 && !pq.empty();count++) {
            if(count == 0) ans[pq.top().second] = "Gold Medal";
            else if(count == 1) ans[pq.top().second] = "Silver Medal";
            else ans[pq.top().second] = "Bronze Medal";
            pq.pop();
        }
        int pos = 4;
        while(!pq.empty()) {
            auto [val, index] = pq.top();
            pq.pop();
            ans[index] = to_string(pos);
            pos++;
        }
        return ans;
    }
};