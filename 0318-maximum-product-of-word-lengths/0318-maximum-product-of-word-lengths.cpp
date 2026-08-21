class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> masks;
        vector<int> lengths;
        for(auto word : words) {
            int mask = 0;
            for(char c : word) {
                mask |= (1 << (c - 'a'));
            }
            masks.push_back(mask);
            lengths.push_back(word.length());
        }
        int ans = 0;
        for(int i=0;i<masks.size()-1;i++) {
            for(int j=i+1;j<masks.size();j++) {
                if((masks[i] & masks[j]) == 0) ans = max(ans, lengths[i] * lengths[j]);
            }
        }
        return ans;
    }
};