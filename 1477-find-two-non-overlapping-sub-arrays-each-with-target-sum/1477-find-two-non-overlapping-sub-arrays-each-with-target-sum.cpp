class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> index(n, INT_MAX);
        int left = 0, sum = 0, right = 0;
        while(right < n) {
            sum += nums[right];
            while(left <= right && sum >= target) {
                if(sum == target) {
                    index[left] = right - left + 1;
                }
                sum -= nums[left];
                left++;
            }
            right++;
        }
        vector<int> candidateAtEnd(n, INT_MAX);
        for(int i=0;i<n;i++) {
            if(index[i] != INT_MAX) {
                int start = i;
                int length = index[i];
                int end = i + index[i] - 1;
                candidateAtEnd[end] = min(length, candidateAtEnd[end]);
            }
        }
        vector<int> prefix(n);
        prefix[0] = candidateAtEnd[0];
        for(int i=1;i<n;i++) {
            prefix[i] = min(prefix[i-1], candidateAtEnd[i]);
        }
        vector<int> suffix(n);
        suffix[n-1] = index[n-1];
        for(int i=n-2;i>=0;i--) {
            suffix[i] = min(suffix[i+1], index[i]);
        }
        int ans = INT_MAX;
        for(int i=0;i<n-1;i++) {
            if(prefix[i] == INT_MAX || suffix[i+1] == INT_MAX) continue;
            ans = min(ans, prefix[i] + suffix[i+1]);
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};