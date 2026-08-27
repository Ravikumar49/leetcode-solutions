class Solution {
public:
    bool valid(string comp) {
        int value = stoi(comp);
        if(value >= 0 && value <= 255) return true;
        return false;
    }
    void backtrack(int part, int index, string s, string curr, vector<string>& res) {
        if(index == s.size()) {
            if(part == 4) {
                res.push_back(curr);
            }
            return;
        }
        if(part == 4) return;
        int oldSize = curr.size();
        if(s[index] == '0') {
            if(index!=0) curr.push_back('.');
            curr.push_back(s[index]);
            backtrack(part+1, index+1, s, curr, res);
        }
        else {
            for(int len=1;len<=3;len++) {
                if(index + len <= s.size()) {
                    string comp = s.substr(index, len);
                    if(!valid(comp)) continue;
                    int oldSize = curr.size();
                    if(index != 0) curr += '.';
                    curr += comp;
                    backtrack(part+1, index+len, s, curr, res);
                    curr.resize(oldSize);
                }
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> res;
        string curr;
        backtrack(0, 0, s, curr, res);
        return res;
    }
};