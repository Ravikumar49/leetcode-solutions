class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> freq;
        for(char c : tasks) freq[c]++;
        priority_queue<int> pq;
        queue<pair<int, int>> cooldown;
        for(auto [task, count] : freq) pq.push(count);
        int time = 0;
        while(!pq.empty() || !cooldown.empty()) {
            while(!cooldown.empty() && cooldown.front().second <= time) {
                pq.push(cooldown.front().first);
                cooldown.pop();
            }
            if(!pq.empty()) {
                int remaining = pq.top();
                pq.pop();
                remaining--;
                if(remaining > 0) cooldown.push({remaining, time+n+1});
            }
            time++;
        }
        return time;
    }
};