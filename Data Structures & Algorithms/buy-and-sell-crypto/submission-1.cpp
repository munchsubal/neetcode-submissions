class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        int buy = prices.size() - 2;
        int sell = prices.size() - 1;

        int max_profit = 0;
        while (buy >= 0) {
            if (prices[buy] > prices[sell]) {
                sell = buy;
            }
            else {
                max_profit = max(prices[sell] - prices[buy], max_profit);
            }
            buy--;
        }

        return max_profit;
    }
};
