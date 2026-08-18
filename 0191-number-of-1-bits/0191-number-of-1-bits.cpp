class Solution {
public:
    int hammingWeight(int n) {
        int steps = 0;
        while(n > 0) {
            n = n & (n-1);
            steps++;
        }
        return steps;
    }
};