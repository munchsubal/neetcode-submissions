class Solution {
private:
    int solve(int idx, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (idx == prices.size()) return 0;

        if (dp[idx][buy] != -1) return dp[idx][buy];

        if (buy == 2) {
            return solve(idx + 1, 1, prices, dp);
        }

        if (buy == 1) {
            int take = solve(idx + 1, 0, prices, dp) - prices[idx];
            int not_take = solve(idx + 1, 1, prices, dp);

            return dp[idx][buy] = max(take, not_take);
        }     

        int sell = solve(idx + 1, 2, prices, dp) + prices[idx];
        int not_sell = solve(idx + 1, 0, prices, dp);

        return dp[idx][buy] = max(sell, not_sell);
    }
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int> (3, -1));
        return solve(0, 1, prices, dp);
    }
};
