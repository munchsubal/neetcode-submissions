class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i =0; i<n; i++) {
            total += nums[i];
        }

        if (total % 2 != 0) return false;
        
        int target = total / 2;
        vector<vector<bool>> dp(n+1, vector<bool> (target + 1, false));
        dp[n][0] = true;

        for (int idx=n-1; idx>=0; idx--) {
            for (int targ=0; targ <= target; targ++) {
                bool take = false;
                if (targ - nums[idx] >= 0) {
                    take = dp[idx+1][targ - nums[idx]];
                }
                bool not_take = dp[idx+1][targ];
                dp[idx][targ] = take || not_take;
            }
        }

        return dp[0][target];
    }
};
