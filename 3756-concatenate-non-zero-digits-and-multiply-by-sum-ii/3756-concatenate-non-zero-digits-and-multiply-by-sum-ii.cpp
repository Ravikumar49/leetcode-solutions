class Solution {
public:
    const long long MOD = 1000000007;
    int number(vector<long long>& pref, int l, int r, vector<int>& count, vector<long long>& pow10) {
        int x;
        if(l == 0) {
           return pref[r];
        }
        else {
            int length = count[r] - count[l-1];
            x = (((1LL * pref[r] - pref[l-1] * pow10[length]) % MOD + MOD) % MOD);
        }
        return x;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int m = s.size();
        vector<int> arr(m);
        vector<int> prefix(m);
        vector<long long> pref(m);
        vector<int> count(m, 0);
        vector<long long> pow10(m);
        arr[0] = s[0] - '0';
        count[0] = arr[0] == 0 ? 0 : 1;
        prefix[0] = s[0] - '0';
        pref[0] = s[0] - '0';
        pow10[0] = 1;
        for(int i=1;i<m;i++) {
            arr[i] = s[i] - '0';
            prefix[i] = prefix[i-1] + arr[i];
            if(arr[i] != 0) {
                pref[i] = (pref[i-1] * 10 + arr[i]) % MOD;
                count[i] = count[i-1] + 1;
            }
            else {
                pref[i] = pref[i-1];
                count[i] = count[i-1];
            }
            pow10[i] = (pow10[i-1] * 10) % MOD;
        }
        int n = queries.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            int x = number(pref, l, r, count, pow10);
            int sum = prefix[r] - prefix[l] + arr[l];
            long long fin = (1LL * x * sum) % MOD;
            ans[i] = fin;
        }
        return ans;
    }
};