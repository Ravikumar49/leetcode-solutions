class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string str = "123456789";
        vector<int> ans;
        for(int len=2;len<10;len++) {
            for(int start = 0;start<=str.length() - len;start++) {
                int digit = stoi(str.substr(start, len));
                if(digit >= low && digit <= high) {
                    ans.push_back(digit);
                }
            }
        }
        return ans;
    }
};