class Solution {
private:
    int solve(int idx, int m, int alice, vector<int>& piles, vector<vector<vector<int>>>& dp) {
        if (idx >= piles.size()) return 0;

        if (dp[idx][m][alice] != -1) return dp[idx][m][alice];

        int total = 0;
        int score = alice ? 0 : INT_MAX;
        for (int x=1; x<=2*m; x++) {
            if (idx + x > piles.size()) {
                break;
            }
            
            total += piles[idx + x - 1];
            if (alice) {
                score = max(score, solve(idx + x, max(x, m), 0, piles, dp) + total);
            }
            else {
                score = min(score, solve(idx + x, max(x, m), 1, piles, dp));
            }
        }

        return dp[idx][m][alice] = score;
    }
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        int m = INT_MIN;
        for (int i=0; i<piles.size(); i++) {
            m = max(m, piles[i]);
        }

        vector<vector<vector<int>>> dp(n, vector<vector<int>> (n + 1, vector<int> (2, -1)));
        return solve(0, 1, 1, piles, dp);
    }
};