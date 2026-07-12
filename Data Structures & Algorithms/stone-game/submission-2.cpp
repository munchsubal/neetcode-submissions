class Solution {
private:
    int solve(int start, int end, vector<int>& piles, vector<vector<int>>& dp) {
        if (start > end) {
            return 0;
        }

        if (dp[start][end] != -1) return dp[start][end];

        if ((start + end) % 2 == 1) {
            int pick_first = solve(start + 1, end, piles, dp) + piles[start];
            int pick_last = solve(start, end - 1, piles, dp) + piles[end];

            return dp[start][end] = max(pick_first, pick_last);
        }

        int pick_first = solve(start + 1, end, piles, dp);
        int pick_last = solve(start, end - 1, piles, dp);

        return dp[start][end] = max(pick_first, pick_last);
    }
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));

        int total = 0;
        for (int i=0; i<piles.size(); i++) {
            total += piles[i];
        }

        int best = solve(0, n - 1, piles, dp);
        if (best > total - best) {
            return true;
        }
        return false;
    }
};