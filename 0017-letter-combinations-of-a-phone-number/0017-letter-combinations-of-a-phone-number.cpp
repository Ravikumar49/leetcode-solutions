class Solution {
public:
    void backtrack(string digits, int index, unordered_map<char, string>& map, string curr, vector<string>& res) {
        if(index == digits.size()) {
            res.push_back(curr);
            return;
        }
        for(char c : map[digits[index]]) {
            curr.push_back(c);
            backtrack(digits, index+1, map, curr, res);
            curr.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mp = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}};
        vector<string> res;
        string curr;
        backtrack(digits, 0, mp, curr, res);
        return res;
    }
};