class Solution {
public:
    int search(int x) {
        int start = 1;
        int end = x;
        while(start <= end) {
            int mid = start + (end - start) / 2;
            long long val = static_cast<long long>(mid) * mid;
            if(val == x) return mid;
            if(val > x) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        return static_cast<int>(round(end));
    }
    int mySqrt(int x) {
        if(x == 0 || x == 1) return x;
        return search(x);
    }
};