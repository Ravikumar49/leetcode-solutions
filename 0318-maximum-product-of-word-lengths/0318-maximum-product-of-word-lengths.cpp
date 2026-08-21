class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mp;
        for(auto word : words) {
            int mask = 0;
            for(char c : word) {
                mask |= (1 << (c - 'a'));
            }
            mp[mask] = max(mp[mask], (int)word.length());
        }
        int ans = 0;
        for(auto [mask1, length1] : mp) {
            for(auto [mask2, length2] : mp) {
                if((mask1 & mask2) == 0) ans = max(ans, length1 * length2);
            }
        }
        return ans;
    }
};