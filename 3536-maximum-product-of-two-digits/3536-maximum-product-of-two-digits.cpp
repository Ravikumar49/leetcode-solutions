class Solution {
public:
    int maxProduct(int n) {
        int largest = -1, secondLargest = -2;
        while(n > 0) {
            int rem = n % 10;
            if(rem >= largest) {
                secondLargest = largest;
                largest = rem;
            }
            else if(rem >= secondLargest && rem < largest) {
                secondLargest = rem;
            }
            n /= 10;
        }
        return largest * secondLargest;
    }
};