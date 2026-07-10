class Solution {
private:
    bool solve(int idx, int target, vector<int>& nums, vector<vector<int>>& dp) {
        if (idx > nums.size() - 1){
            if (target == 0) return true;
            return false;
        }

        if (target < 0) return false;

        if (dp[idx][target] != -1) return dp[idx][target]; 

        bool notTake = solve(idx + 1, target, nums, dp);
        target -= nums[idx];
        bool take = solve(idx + 1, target, nums, dp);
        target += nums[idx];

        dp[idx][target] = take || notTake;

        return dp[idx][target];
    }
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int total = 0;
        for (int i=0; i<nums.size(); i++) {
            total += nums[i];
        }

        if (total % 2 != 0) {
            return false;
        }

        int target = total / 2;
        vector<vector<int>> dp (n, vector<int> (target + 1, -1));
        return solve(0, target, nums, dp);
    }
};
