class Solution {
public:
    int sumOfDigits(int n) {
        int sum = 0;
        while(n > 0) {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<tuple<int, int, int>> arr;
        for(int i=0;i<n;i++) {
            int sum = sumOfDigits(nums[i]);
            arr.push_back({sum, nums[i], i});
        }
        sort(arr.begin(), arr.end());
        vector<bool> visited(n, false);
        int ans = 0;
        for(int i=0;i<n;i++) {
            int original = get<2>(arr[i]);
            int cycleLen = 0;
            while(!visited[original]) {
                visited[original] = true;
                cycleLen++;
                original = get<2>(arr[original]);
            }
            if(cycleLen > 0) ans += cycleLen - 1;
        }
        return ans;
    }
};