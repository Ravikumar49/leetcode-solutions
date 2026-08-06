class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadend(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;
        if(deadend.count("0000")) return -1;
        int steps = 0;
        q.push("0000");
        while(!q.empty()) {
            int size = q.size();
            for(int i=0;i<size;i++) {
                string curr = q.front();
                q.pop();
                if(curr == target) return steps;
                visited.insert(curr);
                for(int i=0;i<=3;i++) {
                    char c = curr[i];
                    int digit = c - '0';
                    int upDigit = (digit + 1) % 10;
                    int downDigit = (digit + 9) % 10;
                    curr[i] = upDigit + '0';
                    if(!deadend.count(curr) && !visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }
                    curr[i] = c;
                    curr[i] = downDigit + '0';
                    if(!deadend.count(curr) && !visited.count(curr)) {
                        q.push(curr);
                        visited.insert(curr);
                    }
                    curr[i] = c;
                }
            }
            steps++;
        }
        return -1;
    }
};