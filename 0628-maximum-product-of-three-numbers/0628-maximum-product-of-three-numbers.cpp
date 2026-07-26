class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return nums[0] * nums[1] * nums[2];
        int largest = INT_MIN, secondLargest = INT_MIN + 1, thirdLargest = INT_MIN + 2, smallest = INT_MAX, secondSmallest = INT_MAX - 1;
        for(int i=0;i<n;i++) {
            if(nums[i] >= largest) {
                thirdLargest = secondLargest;
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] >= secondLargest && nums[i] < largest) {
                thirdLargest = secondLargest;
                secondLargest = nums[i];
            }
            else if(nums[i] >= thirdLargest && nums[i] < secondLargest) {
                thirdLargest = nums[i];
            }
            if(nums[i] <= smallest) {
                secondSmallest = smallest;
                smallest = nums[i];
            }
            else if(nums[i] <= secondSmallest && nums[i] > smallest) {
                secondSmallest = nums[i];
            }
        }
        int prod1 = largest * secondLargest * thirdLargest;
        int prod2 = smallest * secondSmallest * largest;
        return max(prod1, prod2);
    }
};