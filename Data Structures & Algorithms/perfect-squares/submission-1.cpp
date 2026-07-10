class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int targ=1; targ<=n; targ++) {
            for (int j=1; j<=targ; j++) {
                int square = j*j;
                if (targ - square >= 0) {
                    dp[targ] = min(dp[targ], 1 + dp[targ - square]);
                }
            }
        }

        return dp[n];
    }
};