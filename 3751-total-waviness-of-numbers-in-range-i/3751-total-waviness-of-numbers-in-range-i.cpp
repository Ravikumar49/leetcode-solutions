class Solution {
public:
    int waviness(int n) {
        string str = to_string(n);
        int loc = 0;
        for(int i=1;i<str.size()-1;i++) {
            if(str[i] > str[i-1] && str[i] > str[i+1]) {
                loc++;
            }
            else if(str[i] < str[i-1] && str[i] < str[i+1]) {
                loc++;
            }
        }
        return loc;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int i=num1;i<=num2;i++) {
            if(i < 100) continue;
            ans += waviness(i);
        }
        return ans;
    }
};