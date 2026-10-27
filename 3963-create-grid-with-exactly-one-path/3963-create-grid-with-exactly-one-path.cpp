class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> ans;
        string firstRow = "";
        for(int i=0;i<n;i++) firstRow += '.';
        ans.push_back(firstRow);
        string rest = "";
        for(int i=0;i<n-1;i++) rest += '#';
        rest += '.';
        for(int i=0;i<m-1;i++) ans.push_back(rest);
        return ans;
    }
};