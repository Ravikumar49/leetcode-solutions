class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> copy(n);
        for(int i=0;i<n;i++) copy[i] = arr[i];
        sort(copy.begin(), copy.end());
        unordered_map<int, int> map;
        int rank = 0;
        for(auto &x : copy) {
            if(map.find(x)!=map.end()) {
                map[x] = rank;
            }
            else {
                rank++;
                map[x] = rank;
            }
        }
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            ans[i] = map[arr[i]];
        }
        return ans;
    }
};