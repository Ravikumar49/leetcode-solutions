class Solution {
public:
    string palindromeForm(string leftHalf, string middle) {
        string rightHalf = leftHalf;
        reverse(rightHalf.begin(), rightHalf.end());
        return leftHalf + middle + rightHalf;
    }
    string backtrack(int i, vector<int>& freq, string& target, string& res, string middle) {
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
                return palindromeForm(res, middle);
            }
            res.pop_back();
            j--;
        }
        if(j < 0) return "";
        return palindromeForm(res, middle);
    }
    string lexPalindromicPermutation(string s, string target) {
        int n = s.size();
        int oddCount = 0;
        vector<int> freq(26, 0);
        for(char c : s) {
            freq[c - 'a']++;
        }
        string middle = "";
        for(char c='a';c<='z';c++) {
            if(freq[c - 'a']%2 != 0) {
                oddCount++;
                middle = c;
            }
            freq[c - 'a'] /= 2;
        }
        if(oddCount > 1) return "";
        string leftHalf = "";
        for(int i=0;i<target.size()/2;i++) {
            int c = target[i] - 'a';
            if(freq[c] > 0) {
                freq[c]--;
                leftHalf.push_back(target[i]);
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
                    leftHalf.push_back(k + 'a');
                    for (int c = 0; c < 26; c++) {
                        while (freq[c] > 0) {
                            leftHalf.push_back(c + 'a');
                            freq[c]--;
                        }
                    }
                    return palindromeForm(leftHalf, middle);
                }
                return backtrack(i, freq, target, leftHalf, middle);
            }
        }
        string newTarget = target.substr(0, target.size()/2);
        if(leftHalf == newTarget) {
            string candidate = palindromeForm(leftHalf, middle);
            if(candidate > target) {
                return candidate;
            }
            return backtrack(n/2, freq, newTarget, leftHalf, middle);
        }
        return palindromeForm(leftHalf, middle);
    }
};