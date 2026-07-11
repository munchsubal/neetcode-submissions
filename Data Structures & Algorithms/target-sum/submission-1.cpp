class Solution {
private:
    int solve(int idx, int target, vector<int>& nums) {
        if (target == 0 && idx < 0) return 1;
        if (idx < 0) return 0;

        int take_plus = 0, take_minus = 0;
        
        take_plus = solve(idx - 1, target - nums[idx], nums);
        take_minus = solve(idx - 1, target + nums[idx], nums);

        return take_plus + take_minus;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        return solve(n - 1, target, nums);
    }
};

