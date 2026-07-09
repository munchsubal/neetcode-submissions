class Solution {
private:
    int solve(vector<int>& nums, int l, int r) {
        int n = r - l + 1;

        vector<int> dp(nums.size(), 0);
        dp[l] = nums[l];
        dp[l + 1] = max(nums[l], nums[l + 1]);

        for (int i=l+2; i<=r; i++) {
            int pick = nums[i] + dp[i-2];
            int not_pick = dp[i-1];
            dp[i] = max(pick, not_pick);
        }

        return dp[r];
    }
public:
    int rob(vector<int>& nums) {
        int l = 0;
        int r = nums.size() - 1;

        if (r == 0) {
            return nums[0];
        }
        if (r == 1) {
            return max(nums[0], nums[1]);
        }
        return max(solve(nums, l, r-1), solve(nums, l+1, r));
    }
};
