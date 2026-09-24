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
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++) {
            if(i == sumOfDigits(nums[i])) return i;
        }
        return -1;
    }
};