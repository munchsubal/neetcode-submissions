class Solution {
private:
    int solve(int idx1, int idx2, string s, string t, vector<vector<int>>& dp) {
        if (idx2 < 0) return 1;
        if (idx1 < idx2) return 0;

        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if (s[idx1] == t[idx2]) {
            return dp[idx1][idx2] = solve(idx1 - 1, idx2 - 1, s, t, dp) + solve(idx1 - 1, idx2, s, t, dp);
        }
        return dp[idx1][idx2] = solve(idx1 - 1, idx2, s, t, dp);
    }
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> dp(n, vector<int> (m, -1));
        return solve(n - 1, m - 1, s, t, dp);
    }
};
