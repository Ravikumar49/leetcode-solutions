class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_map<char, int> bit= {{'A', 0}, {'C', 1}, {'G', 2}, {'T', 3}};
        unordered_map<int, int> freq;
        int encoded = 0;
        vector<string> ans;
        for(int i=0;i<s.size();i++) {
            encoded = (encoded << 2) | bit[s[i]];
            int mask = (1 << 20) - 1;
            encoded &= mask;
            if(i >= 9) {
                freq[encoded]++;
                if(freq[encoded] == 2) {
                    ans.push_back(s.substr(i-9, 10));
                }
            }
        }
        return ans;
    }
};