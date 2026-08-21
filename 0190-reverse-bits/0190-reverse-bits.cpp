class Solution {
public:
    int reverseBits(int n) {
        uint32_t ans = 0;
        for(int i=0;i<32;i++) {
            int bit = n & 1;
            ans |= bit << 31-i;
            n >>= 1;
        }
        return ans;
    }
};