class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> openParanthesesIndices;
        string result;
        for(char currentChar : s) {
            if(currentChar == '(') {
                openParanthesesIndices.push(result.length());
            }
            else if(currentChar == ')') {
                int start = openParanthesesIndices.top();
                openParanthesesIndices.pop();
                reverse(result.begin() + start, result.end());
            }
            else {
                result += currentChar;
            }
        }
        return result;
    }
};