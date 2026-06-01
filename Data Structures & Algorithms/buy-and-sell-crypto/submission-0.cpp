class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();

        vector<int> suffix_max(n, -1);
        for (int i=n-2; i>=0; i--) {
            suffix_max[i] = max(prices[i+1], suffix_max[i+1]);
        }

        int maxProf = 0;
        for (int i=0; i<n; i++) {
            int profit = suffix_max[i] - prices[i] > 0 ? suffix_max[i] - prices[i] : 0;
            if (profit > maxProf) {
                maxProf = profit;
            }
        }

        return maxProf;
    }
};
