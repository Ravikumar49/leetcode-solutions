class Solution {
public:
    int hammingDistance(int x, int y) {
        int n = x ^ y;
        int steps = 0;
        while(n > 0) {
            n &= n-1;
            steps++;
        }
        return steps;
    }
};