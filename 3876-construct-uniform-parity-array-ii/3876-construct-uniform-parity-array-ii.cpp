class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        int parity = nums1[0] % 2;
        bool seenOdd = nums1[0]%2 == 1 ? true : false;
        for(int i=1;i<n;i++) {
            if(nums1[i] % 2 == parity) continue;
            else {
                if(!seenOdd) return false;
            }
            if(nums1[i] % 2 == 1) seenOdd = true;
        }
        return true;
    }
};