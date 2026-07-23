class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> s;
        for(int i=0;i<n;i++) {
            for(int j=i;j<n;j++) {
                int curr = nums[i] ^ nums[j];
                s.insert(curr);
            }
        }
        unordered_set<int> t;
        for(const int &x : s) {
            for(int i=0;i<n;i++) {
                int curr = x ^ nums[i];
                t.insert(curr);
            }
        }
        return t.size();
    }
};