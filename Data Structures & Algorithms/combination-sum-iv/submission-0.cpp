class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(target + 1, 0);
        dp[0] = 1;

        for (int targ=1; targ<=target; targ++) {
            for (int j=0; j<n; j++) {
                if (targ - nums[j] >= 0) {
                    dp[targ] += dp[targ - nums[j]];
                }
            }
        }

        return dp[target];
    }
};