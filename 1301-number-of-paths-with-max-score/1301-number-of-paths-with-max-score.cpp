class Solution {
public:
    const long long MAX= 1000000007;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        vector<vector<pair<int, int>>> dp(m, vector<pair<int, int>>(n, {-1, 0}));
        dp[m-1][n-1] = {0, 1};
        for(int i=m-1;i>=0;i--) {
            for(int j=n-1;j>=0;j--) {
                if(board[i][j] == 'S') continue;
                if(board[i][j] == 'X') {
                    dp[i][j].first = -1;
                    dp[i][j].second = 0;
                }
                else {
                    int bestScore = -1;
                    if(i+1 < m)
                        bestScore = max(bestScore, dp[i+1][j].first);

                    if(j+1 < n)
                        bestScore = max(bestScore, dp[i][j+1].first);

                    if(i+1 < m && j+1 < n)
                        bestScore = max(bestScore, dp[i+1][j+1].first);
                    if(bestScore == -1) continue;
                    if(i+1 < m && dp[i+1][j].first == bestScore)
                        dp[i][j].second += dp[i+1][j].second;

                    if(j+1 < n && dp[i][j+1].first == bestScore)
                        dp[i][j].second += dp[i][j+1].second;

                    if(i+1 < m && j+1 < n && dp[i+1][j+1].first == bestScore)
                        dp[i][j].second += dp[i+1][j+1].second;

                    dp[i][j].second %= MAX;
                    if(board[i][j] == 'E') {
                        dp[i][j].first = bestScore;
                    }
                    else {
                        dp[i][j].first = bestScore + (board[i][j] - '0');
                    }
                }
            }
        }
        if(dp[0][0].first == -1) {
            return {0, 0};
        }
        return {dp[0][0].first, dp[0][0].second};
    }
};