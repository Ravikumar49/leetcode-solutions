class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int n = arr.size();
        vector<int> copy = arr;
        sort(copy.begin(), copy.end());
        unordered_map<int, int> map;
        int rank = 1;
        for(auto &x : copy) {
            if(!map.count(x)) {
                map[x] = rank++;
            }
        }
        for(int &x : arr) {
            x = map[x];
        }
        return arr;
    }
};