class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for(auto r : reservedSeats) {
            int row = r[0];
            int col = r[1];
            rowMask[row] |= (1 << col);
        }
        int groupA = (1 << 9) | (1 << 8) | (1 << 7) | (1 << 6);
        int groupB = (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4);
        int groupC = (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2);
        int total = 0;
        for(auto [r, k] : rowMask) {
            if(((groupA & k) == 0) && ((groupC & k) == 0)) total += 2;
            else if (((groupA & k) == 0) || ((groupC & k) == 0)) total++;
            else if((groupB & k) == 0) total++;
        }
        total += 2 * (n - rowMask.size());
        return total;
    }
};