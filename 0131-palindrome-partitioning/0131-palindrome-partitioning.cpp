class Solution {
public:
    bool isPalindrome(string s, int left, int right) {
        while(left <= right) {
            if(s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    void backtrack(string s, int start, vector<string>& curr, vector<vector<string>>& res) {
        if(start == s.size()) {
            res.push_back(curr);
            return;
        }
        for(int end=start;end<s.size();end++) {
            if(isPalindrome(s, start, end)) {
                curr.push_back(s.substr(start, end - start + 1));
                backtrack(s, end+1, curr, res);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> curr;
        backtrack(s, 0, curr, res);
        return res;
    }
};