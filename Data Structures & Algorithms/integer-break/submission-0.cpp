class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1, INT_MIN);
        int max_num = ceil(n / 2.0);
        dp[0] = 0;
        dp[1] = 0;
        dp[2] = 1;

        for (int i=3; i<=n; i++) {
            for (int j = 1; j <= max_num; j++) {
                if (i - j >= 0) {
                    dp[i] = max(dp[i], j*max(i-j, dp[i - j]));
                }
            }
        }

        return dp[n];
    }
};