class Solution {
public:
    int numSquares(int n) {
        vector<int> perfect_squares;
        for (int i=1; i<=100; i++) {
            perfect_squares.push_back(i*i);
        }

        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;

        for (int targ=1; targ<=n; targ++) {
            for (int j=0; j<perfect_squares.size(); j++) {
                if (targ - perfect_squares[j] >= 0) {
                    dp[targ] = min(dp[targ], 1 + dp[targ - perfect_squares[j]]);
                }
            }
        }

        return dp[n];
    }
};