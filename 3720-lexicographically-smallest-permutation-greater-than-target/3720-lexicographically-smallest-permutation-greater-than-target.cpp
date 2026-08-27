class Solution {
public:
    string backtrack(int i, vector<int>& freq, string& target, string& res) {
        int j = i - 1;
        while(j >= 0) {
            freq[target[j] - 'a']++;
            int k;
            for(k=target[j] - 'a' + 1;k<26;k++) {
                if(freq[k] > 0) break;
            }
            if(k < 26) {
                freq[k]--;
                res.back() = k + 'a';
                for(int i=0;i<26;i++) {
                    while(freq[i] > 0) {
                        res.push_back(i + 'a');
                        freq[i]--;
                    }
                }
                return res;
            }
            res.pop_back();
            j--;
        }
        if(j < 0) return "";
        return res;
    }
    string lexGreaterPermutation(string s, string target) {
        vector<int> freq(26, 0);
        int n = target.size();
        for(char c : s) freq[c - 'a']++;
        string res = "";
        for(int i=0;i<target.size();i++) {
            int c = target[i] - 'a';
            if(freq[c] > 0) {
                freq[c]--;
                res.push_back(target[i]);
            }
            else {
                int k;
                for(k=c+1;k<26;k++) {
                    if(freq[k] > 0) {
                        break;
                    }
                }
                if (k < 26) {
                    freq[k]--;
                    res.push_back(k + 'a');
                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            res.push_back(c + 'a');
                            freq[c]--;
                        }
                    }
                    return res;
                }
                return backtrack(i, freq, target, res);
            }
        }
        if(res == target) {
            res = backtrack(n, freq, target, res);
        }
        return res;
    }
};