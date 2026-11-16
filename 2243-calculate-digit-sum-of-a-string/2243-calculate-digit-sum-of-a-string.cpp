class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();
        while(s.size() > k) {
            string str;
            int idx = 0;
            n = s.size();
            while(idx < n) {
                int sum = 0;
                for(int i=idx;i<min(n, idx+k);i++) {
                    sum += s[i] - '0';
                }
                str += to_string(sum);
                idx += k;
            }
            s = str;
        }
        return s;
    }
};