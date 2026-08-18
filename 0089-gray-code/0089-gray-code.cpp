class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> curr = {0};
        for(int bits=1;bits<=n;bits++) {
            int add = 1 << (bits-1);
            int size = curr.size();
            for(int i=size-1;i>=0;i--) {
                curr.push_back(curr[i] + add);
            } 
        }
        return curr;
    }
};