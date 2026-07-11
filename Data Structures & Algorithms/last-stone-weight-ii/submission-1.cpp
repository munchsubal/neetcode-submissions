class Solution {
private: 
    int solve(int idx, int capacity, vector<int>& stones, vector<vector<int>>& dp) {
        if (idx < 0) return 0;
        if (capacity < 0) return 0;

        if (dp[idx][capacity] != -1) return dp[idx][capacity];

        int pick = 0;
        if (stones[idx] <= capacity) {
            pick = stones[idx] + solve(idx - 1, capacity - stones[idx], stones, dp);
        }

        int not_pick = solve(idx - 1, capacity, stones, dp);

        return dp[idx][capacity] = max(pick, not_pick);
    }
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;

        for (int i=0; i<stones.size(); i++) {
            total += stones[i];
        }

        int capacity = total / 2;
        vector<vector<int>> dp(n, vector<int> (capacity + 1, -1));
        int best = solve(n - 1, capacity, stones, dp);

        return abs(total - 2 * best);
    }
};