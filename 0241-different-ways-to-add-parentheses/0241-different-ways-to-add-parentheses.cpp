class Solution {
public:
    int solve(int x, int y, char op) {
        if(op == '+') return x + y;
        if(op == '-') return x - y;
        if(op == '*') return x * y;
        return 0;
    }
    vector<int> diffWaysToCompute(string expression) {
        int n = expression.size();
        vector<int> res;
        for(int i=0;i<n;i++) {
            char ch = expression[i];

            if(!isdigit(ch)) {
                vector<int> leftValues = diffWaysToCompute(expression.substr(0, i));
                vector<int> rightValues = diffWaysToCompute(expression.substr(i+1));
                for(int leftVal : leftValues) {
                    for(int rightVal : rightValues) {
                        res.push_back(solve(leftVal, rightVal, ch));
                    }
                }
            }
        }
        if(res.empty()) {
            res.push_back(stoi(expression));
        }
        return res;
    }
};