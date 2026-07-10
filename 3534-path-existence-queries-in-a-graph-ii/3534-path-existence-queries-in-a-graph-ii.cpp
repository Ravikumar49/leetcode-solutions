class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> ans(queries.size());
        vector<pair<int, int>> node(n);
        for(int i=0;i<n;i++) {
            node[i].first = nums[i];
            node[i].second = i;
        }
        sort(node.begin(), node.end());
        vector<int> pos(n);
        for(int i=0;i<n;i++) {
            pos[node[i].second] = i;
        }
        vector<int> next(n);
        int j = 0;
        for(int i=0;i<n;i++) {
            while(j<n && node[j].first - node[i].first <= maxDiff) {
                j++;
            }
            next[i] = j-1;
        }
        int LOG = floor(log2(n)) + 1;
        vector<vector<int>> jump(LOG, vector<int>(n, -1));
        for(int i=0;i<n;i++) {
            jump[0][i] = next[i];
        }
        for(j=1;j<LOG;j++) {
            for(int i=0;i<n;i++) {
                if(jump[j-1][i] != -1) {
                    jump[j][i] = jump[j-1][ jump[j-1][i] ];
                }
            }
        }
        for(int i=0;i<queries.size();i++) {
            int L = pos[queries[i][0]];
            int R = pos[queries[i][1]];
            if(L > R) swap(L, R);
            int current = L;
            int answer = 0;
            for(int k=LOG-1;k>=0;k--) {
                if(jump[k][current] != -1 && jump[k][current] < R) {
                    current = jump[k][current];
                    answer += (1 << k);
                }
            }
            if(current == R) {
                ans[i] = answer;
            }
            else if(next[current] >= R) {
                ans[i] = 1 + answer;
            }
            else {
                ans[i] = -1;
            }
        }
        return ans;
    }
};