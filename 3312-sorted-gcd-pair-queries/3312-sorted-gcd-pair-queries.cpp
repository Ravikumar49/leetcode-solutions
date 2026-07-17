class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> freq(mx + 1, 0);
        for(int &x : nums) {
            freq[x] += 1;
        }
        vector<long long> divisible(mx + 1);
        for(int d=1;d<=mx;d++) {
            long long cnt = 0;
            for(int multiple=d;multiple<=mx;multiple+=d) {
                cnt += freq[multiple];
            }
            divisible[d] = (cnt * (cnt - 1)) / 2;
        }
        vector<long long> exact(mx + 1, 0);
        for(int d=mx;d>=1;d--) {
            exact[d] = divisible[d];
            for(int multiple=2*d;multiple<=mx;multiple+=d) {
                exact[d] -= exact[multiple];
            }
        }
        vector<long long> pref(mx + 1);
        pref[0] = 0;
        for(int d=1;d<=mx;d++) {
            pref[d] = pref[d-1] + exact[d];
        }
        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++) {
            ans[i] = upper_bound(pref.begin(), pref.end(), queries[i]) - pref.begin();
        }
        return ans;
    }
};