class Solution {
private:
    int solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx == 0) {
            if (target == 0 && nums[0] == 0) return 2;
            if (target == 0 || nums[0] == target) return 1;
            return 0;
        }

        if (dp[idx][target] != -1) return dp[idx][target];

        int take = 0;
        if (nums[idx] <= target) {
            take = solve(idx - 1, target - nums[idx], nums, dp);
        }
        int not_take = solve(idx - 1, target, nums, dp);

        return dp[idx][target] = take + not_take;
    }      
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int total = 0;
        for (int i=0; i<nums.size(); i++) {
            total += nums[i];
        }

        int targ = (total - target) / 2;
        if ((total - target) % 2 != 0) return 0;

        vector<vector<int>> dp(n, vector<int> (targ + 1, -1));

        return solve(n - 1, targ, nums, dp);
    }
};

