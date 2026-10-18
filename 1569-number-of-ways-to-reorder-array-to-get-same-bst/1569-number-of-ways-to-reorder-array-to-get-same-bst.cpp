class Solution {
public:
    int numOfWays(vector<int>& nums) {
        int m = nums.size();
        table.resize(m + 1);
        for(int i=0;i<m;i++) {
            table[i] = vector<long long>(i+1, 1);
            for(int j=1;j<i;j++) {
                table[i][j] = (table[i-1][j-1] + table[i-1][j]) % MOD;
            }
        }
        return (dfs(nums) - 1) % MOD;
    }

private:
    vector<vector<long long>> table;
    long long MOD = 1e9 + 7;

    long long dfs(vector<int>& nums) {
        int m = nums.size();
        if(m < 3) return 1;

        vector<int> leftNodes, rightNodes;
        for(int i=1;i<m;i++) {
            if(nums[i] < nums[0]) leftNodes.push_back(nums[i]);
            else rightNodes.push_back(nums[i]);
        }

        long long leftWays = dfs(leftNodes) % MOD;
        long long rightWays = dfs(rightNodes) % MOD;

        return (((leftWays * rightWays) % MOD * table[m-1][leftNodes.size()]) % MOD);
    }
};