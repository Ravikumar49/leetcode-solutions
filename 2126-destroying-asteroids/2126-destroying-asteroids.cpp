class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long m = mass;
        bool ans = true;
        for(auto &x : asteroids) {
            if(x <= m) {
                m += x;
            }
            else {
                ans = false;
                break;
            }
        }
        return ans;
    }
};