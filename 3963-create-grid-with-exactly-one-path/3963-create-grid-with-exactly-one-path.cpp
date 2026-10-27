class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string firstRow = string(n, '.');
        string rest = string(n-1, '#') + '.';
        ans.push_back(firstRow);
        for(int i=0;i<m-1;i++) ans.push_back(rest);
        return ans;
    }
};