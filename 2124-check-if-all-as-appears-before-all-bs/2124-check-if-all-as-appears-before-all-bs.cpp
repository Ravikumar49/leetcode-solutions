class Solution {
public:
    bool checkString(string s) {
        int n = s.size();
        bool foundB = false;
        int indexA = -1;
        int indexB = n;
        for(int i=0;i<n;i++) {
            if(s[i] == 'a') indexA = i;
            else if(!foundB && s[i] == 'b') {
                indexB = i;
                foundB = true;
            }
        }
        return indexA < indexB;
    }
};