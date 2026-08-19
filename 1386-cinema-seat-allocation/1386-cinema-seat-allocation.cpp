class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> rowMask;
        for(auto seats : reservedSeats) {
            int row = seats[0];
            int col = seats[1];
            rowMask[row] |= (1 << col);
        }
        int groupA, groupB, groupC;
        groupA = (1 << 9) | (1 << 8) | (1 << 7) | (1 << 6);
        groupB = (1 << 7) | (1 << 6) | (1 << 5) | (1 << 4);
        groupC = (1 << 5) | (1 << 4) | (1 << 3) | (1 << 2);
        int total = 0;
        for(auto [r, k] : rowMask) {
            if((k & groupA) == 0 && (k & groupC) == 0) total += 2;
            else if((k & groupA) == 0 || (k & groupC) == 0) total++;
            else if((k & groupB) == 0) total++;
        }
        total += 2 * (n - rowMask.size());
        return total;
    }
};