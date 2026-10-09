class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int insertions = 0;
        int leftCount = 0;
        int index = 0;
        while(index < n) {
            char c = s[index];
            if(c == '(') {
                leftCount++;
                index++;
            }
            else {
                if(leftCount > 0) leftCount--;
                else insertions++;
                if(index < n - 1 && s[index + 1] == ')') index += 2;
                else {
                    insertions++;
                    index++;
                }
            }
        }
        insertions += leftCount * 2;
        return insertions;
    }
};