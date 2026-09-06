class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        priority_queue<pair<int, int>> pq;
        for(int i=0;i<score.size();i++) pq.push({score[i], i});
        vector<string> ans(score.size());
        for(int count=0;count<3 && !pq.empty();count++) {
            auto [val, index] = pq.top();
            if(count == 0) ans[index] = "Gold Medal";
            else if(count == 1) ans[index] = "Silver Medal";
            else ans[index] = "Bronze Medal";
            pq.pop();
        }
        int pos = 4;
        while(!pq.empty()) {
            auto [val, index] = pq.top();
            ans[index] = to_string(pos);
            pq.pop();
            pos++;
        }
        return ans;
    }
};