class Solution {
public:
    void backtrack(int index, int balance, int removed, int& minRemoved, string curr, set<string>& ans, string s) {
        if (removed + (s.size() - index) < minRemoved) return;
        if (balance > s.size() - index) return;
        if(index == s.size()) {
            if(balance == 0) {
                if(removed == minRemoved) {
                    ans.insert(curr);
                }
            }
            return;
        }
        if(s[index] == '(') {
            curr.push_back(s[index]);
            backtrack(index+1, balance+1, removed, minRemoved, curr, ans, s);
            curr.pop_back();
            if(removed < minRemoved) backtrack(index+1, balance, removed+1, minRemoved, curr, ans, s);
        }
        else if(s[index] == ')' && balance >= 0) {
            curr.push_back(s[index]);
            if(balance > 0) backtrack(index+1, balance-1, removed, minRemoved, curr, ans, s);
            curr.pop_back();
            if(removed < minRemoved) backtrack(index+1, balance, removed+1, minRemoved, curr, ans, s);
        }
        else {
            curr.push_back(s[index]);
            backtrack(index+1, balance, removed, minRemoved, curr, ans, s);
        }
    }
    vector<string> removeInvalidParentheses(string s) {
        int n = s.size();
        int balance = 0;
        int removals = 0;
        for(char c : s) {
            if(c == '(') balance++;
            else if(c == ')')  {
                if(balance > 0) balance--;
                else if(balance == 0) removals++;
            }
        }
        string curr;
        set<string> ans;
        int minRemoved = balance + removals;
        backtrack(0, 0, 0, minRemoved, curr, ans, s);
        vector<string> res(ans.begin(), ans.end());
        return res;
    }
};