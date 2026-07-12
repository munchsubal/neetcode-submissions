class Solution {
private:
    int solve(int idx1, int idx2, string word1, string word2, vector<vector<int>>& dp) {
        if (idx1 < 0 && idx2 < 0) return 0;
        if (idx2 < 0) return idx1 + 1;
        if (idx1 < 0) return idx2 + 1;

        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        if (word1[idx1] == word2[idx2]) {
            return dp[idx1][idx2] = solve(idx1 - 1, idx2 - 1, word1, word2, dp);
        }

        int insert = 1 + solve(idx1, idx2 - 1, word1, word2, dp);
        int remove = 1 + solve(idx1 - 1, idx2, word1, word2, dp);
        int replace = 1 + solve(idx1 - 1, idx2 - 1, word1, word2, dp);

        return dp[idx1][idx2] = min(replace, min(insert, remove));
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n, vector<int> (m, -1));
        
        return solve(n-1, m-1, word1, word2, dp);
    }
};
