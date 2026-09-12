class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        bool parity = nums1[0] % 2;
        bool oddSeen = (nums1[0] % 2 != 0);
        for(int i=1;i<n;i++) {
            if(parity == nums1[i] % 2) continue;
            if(!oddSeen) return false;
            if(nums1[i] % 2 == 1) oddSeen = true;
        }
        return true;
    }
};