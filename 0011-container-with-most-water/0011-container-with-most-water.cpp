class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        if(n == 2) return min(height[0], height[1]);
        int i = 0, j = n-1;
        int ans = -1;
        while(i < j) {
            int dist = j - i;
            int len = min(height[i], height[j]);
            int curr = dist * len;
            ans = max(ans, curr);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};