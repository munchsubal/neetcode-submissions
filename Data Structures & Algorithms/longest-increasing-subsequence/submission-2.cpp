class Solution {
private:
    int solve(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp) {
        if (ind == nums.size()) return 0;

        if (dp[ind][prev + 1] != -1) return dp[ind][prev + 1];
        
        int take = 0;
        if (prev == -1 || nums[ind] > nums[prev]) {
            take = 1 + solve(ind + 1, ind, nums, dp);
        }

        int not_take = solve(ind + 1, prev, nums, dp);

        dp[ind][prev + 1] = max(take, not_take);
        return max(take, not_take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n+1, -1));
        return solve(0, -1, nums, dp);
    }
};
