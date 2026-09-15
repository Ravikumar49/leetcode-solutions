class Solution {
public:
    int isPossible(int start, vector<int>& gain) {
        int n = gain.size();
        int tank = 0;
        int count = 0;
        int i = start;
        while(count <= n && tank >= 0) {
            tank += gain[i];
            i = (i + 1) % n;
            count++;
            if(tank < 0) return i;
        }
        return start;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        vector<int> gain(n);
        int total = 0;
        for(int i=0;i<n;i++) {
            gain[i] = gas[i] - cost[i];
            total += gain[i];
        }
        if(total < 0) return -1;
        int start = 0;
        while(start < n) {
            int curr = isPossible(start, gain);
            if(start == curr) return start;
            start = curr;
        }
        return 0;
    }
};