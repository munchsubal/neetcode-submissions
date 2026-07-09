class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        vector<int> dp(n, 0);
        dp[0] = nums[0];

        for (int i=1; i<n; i++) {
            if (i == 1){
                dp[i] = max(nums[i], nums[0]);
            } 
            else {
                dp[i] = max(dp[i-1], dp[i-2] + nums[i]);
            }
        }

        return dp[n-1];

    }
};
