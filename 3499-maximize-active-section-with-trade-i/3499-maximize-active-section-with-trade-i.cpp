class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<char, int>> str;
        s = '1' + s + '1';
        int len = 1;
        for(int i=1;i<s.size();i++) {
            if(s[i] == s[i-1]) {
                len++;
            }
            else {
                str.push_back({s[i-1], len});
                len = 1;
            }
        }
        char ch = s.back();
        str.push_back({ch, len});
        int ans = 0;
        int n = str.size();
        int leftGain, rightGain;
        for(int i=2;i<=n-2;i+=2) {
            if(str[i].first == '1' && str[i-1].first == str[i+1].first) {
                leftGain = str[i-1].second;
                rightGain = str[i+1].second;
            }
            int sum = leftGain + rightGain;
            ans = max(ans, sum);
        }
        int session = 0;
        for(int i=0;i<n;i++) {
            if(str[i].first == '1') session += str[i].second;
        }
        return ans + session - 2;
    }
};