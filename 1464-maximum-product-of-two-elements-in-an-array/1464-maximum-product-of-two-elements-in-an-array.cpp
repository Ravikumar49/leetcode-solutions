class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return (nums[0] - 1) * (nums[1] - 1);
        int largest = INT_MIN, secondLargest = INT_MIN;
        for(int i=0;i<n;i++) {
            if(nums[i] >= largest) {
                secondLargest = largest;
                largest = nums[i];
            }
            else if(nums[i] >= secondLargest) {
                secondLargest = nums[i];
            }
        }
        cout << largest << " : " << secondLargest << endl;
        return (largest - 1) * (secondLargest - 1);
    }
};