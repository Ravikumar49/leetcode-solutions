class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        if(n == 1) return 1;
        int i = 0, j = 0;
        int ans = 0;
        unordered_map<int, int> freq;
        while(i < n) {
            freq[fruits[i]]++;
            while(j < n && freq.size() > 2) {
                freq[fruits[j]]--;
                if(freq[fruits[j]] == 0) {
                    freq.erase(fruits[j]);
                }
                j++;
            }
            ans = max(ans, i-j+1);
            i++;
        }
        return ans;
    }
};