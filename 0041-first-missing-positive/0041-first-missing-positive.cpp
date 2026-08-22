class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int x : nums) mp[x]++;
        int lookUp = 1;
        while(true) {
            if(mp.count(lookUp)) lookUp++;
            else break;
        }
        return lookUp;
    }
};