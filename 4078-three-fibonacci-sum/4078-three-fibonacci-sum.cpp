class Solution {
public:
    vector<long long> fibGen(int n) {
        vector<long long> ans;
        ans.push_back(0);
        ans.push_back(1);
        int sum = 1;
        while(sum <= n) {
            long long a = ans.back();
            long long b = ans[ans.size() - 2];
            sum = a + b;
            ans.push_back(sum);
        }
        return ans;
    }
    bool threeFibonacciSum(int n) {
        vector<long long> ans = fibGen(n);
        int index = 0;
        while(index < ans.size() - 2) {
            long long sum = ans[index] + ans[index + 1] + ans[index + 2];
            if(sum == n) return true;
            index++;
        }
        return false;
    }
};