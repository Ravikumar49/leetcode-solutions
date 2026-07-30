class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res;
        for(int i=0;i<n;i++) {
            res.push_back(nums1[i]);
        }
        for(int j=0;j<m;j++) {
            res.push_back(nums2[j]);
        }
        double sum;
        int total = res.size();
        sort(res.begin(), res.end());
        if(total%2 != 0) {
            return double(res[total/2]);
        }
        sum = double(res[total/2 - 1] + res[total/2]);
        return sum/2;
    }
};