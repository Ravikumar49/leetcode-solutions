class Solution {
public:
    int time_taken(vector<int>& piles, int val) {
        int time = 0;
        for(int i=0;i<piles.size();i++) {
            time += (piles[i] + val - 1)/ val;
        }
        return time;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low < high) {
            int mid = (low + high) / 2;
            int hours = time_taken(piles, mid);
            if(hours > h) low = mid + 1;
            else {
                ans = mid;
                high = mid;
            }
        }
        return ans;
    }
};