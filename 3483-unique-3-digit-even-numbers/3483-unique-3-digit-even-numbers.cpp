class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_map<int, int> freq;
        bool isEven = false;
        for(int x : digits) {
            if(x%2 == 0) isEven = true;
            freq[x]++;
        }
        if(!isEven) return 0;
        int ans = 0;
        int val, curr1, curr2, curr3;
        for(int units=0;units<=8;units+=2) {
            if(freq[units] > 0) {
                val = units;
                curr1 = val;
                freq[units]--;
                for(int tens=0;tens<=9;tens++) {
                    if(freq[tens] > 0) {
                        val = (tens*10) + val;
                        curr2 = val;
                        freq[tens]--;
                        for(int hundred=1;hundred<=9;hundred++) {
                            if(freq[hundred] > 0) {
                                val = (hundred*100) + val;
                                curr3 = val;
                                freq[hundred]--;
                                ans++;
                                freq[hundred]++;
                                val = curr2;
                            }
                        }
                        freq[tens]++;
                        val = curr1;
                    }
                }
                freq[units]++;
            }
        }
        return ans;
    }
};