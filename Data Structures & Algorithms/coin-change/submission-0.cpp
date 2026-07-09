class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int m = amount;
        int n = coins.size();

        vector<int> dp(m+1, 0);
        dp[0] = 0;
        
        for (int i=1; i<=m; i++) {
            int min_coins = INT_MAX;
            for (int j=0; j<n; j++) {
                if (i - coins[j] >= 0 && dp[i - coins[j]] != -1) {
                    min_coins = min(min_coins, 1 + dp[i-coins[j]]);
                }
            }

            dp[i] = min_coins == INT_MAX ? -1 : min_coins;
        }

        return dp[m];
    }
};
