class Solution {
private:
    bool solve(int idx1, int idx2, string s1, string s2, string s3, vector<vector<int>>& dp) {
        int idx3 = idx1 + idx2;
        if (idx3 == s3.size() && idx1 == s1.size() && idx2 == s2.size()) return true;
        if (idx1 == s1.size() && idx2 == s2.size()) return false;

        if (dp[idx1][idx2] != -1) return dp[idx1][idx2];

        bool match1 = false, match2 = false;
        if (idx1 < s1.size() && s1[idx1] == s3[idx3]) {
            match1 = solve(idx1 + 1, idx2, s1, s2, s3, dp);
        }

        if (idx2 < s2.size() && s2[idx2] == s3[idx3]) {
            match2 = solve(idx1, idx2 + 1, s1, s2, s3, dp);
        }

        if (!match1 && !match2) {
            return dp[idx1][idx2] = false;
        }
        return dp[idx1][idx2] = true;
    }
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int t = s3.size();
        vector<vector<int>> dp(n+1, vector<int> (m+1, -1));
        return solve(0, 0, s1, s2, s3, dp);
    }
};
