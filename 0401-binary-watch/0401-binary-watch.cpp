class Solution {
public:
    int countBits(int n) {
        int bits = 0;
        while(n > 0) {
            n &= n-1;
            bits++;
        }
        return bits;
    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> res;
        string curr;
        for(int hours=0;hours<=11;hours++) {
            for(int minutes=0;minutes<=59;minutes++) {
                int total = countBits(hours) + countBits(minutes);
                if(total == turnedOn) {
                    if(minutes < 10) {
                        curr = to_string(hours) + ":0" + to_string(minutes);
                    }
                    else {
                        curr = to_string(hours) + ":" + to_string(minutes);
                    }
                    res.push_back(curr);
                }
            }
        }
        return res;
    }
};